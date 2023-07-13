/**
 * Description: Performs range prefix sum queries and point updates. kth returns
 * first index with prefix query >= k. Source: own Verification:
 * http://www.usaco.org/index.php?page=viewproblem2&cpid=693 Time: O(log n)
 * query and update
 */
const int LG = 21;
template <typename T> struct fenwick {
  int n, lg;
  vector<T> ft;

  fenwick(int _n) : n(_n), lg(LG), ft(n + 1) {}

  fenwick(const vector<T> &a) : n((int)a.size()), lg(LG), ft(n + 1) {
    for (int i = 1; i <= n; ++i) {
      ft[i] += a[i - 1];
      if (i + (i & -i) <= n) {
        ft[i + (i & -i)] += ft[i];
      }
    }
  }

  T query(int i) {
    T ret = 0;
    for (++i; i > 0; i -= (i & -i)) {
      ret += ft[i];
    }
    return ret;
  }

  T query(int l, int r) { return l > r ? 0 : query(r) - query(l - 1); }

  void add(int i, T x) {
    for (++i; i <= n; i += (i & -i)) {
      ft[i] += x;
    }
  }

  int kth(T k) {
    int ret = 0;
    for (int i = lg; i >= 0; i--) {
      ret += 1 << i;
      if (ret <= n && ft[ret] < k)
        k -= ft[ret];
      else
        ret -= 1 << i;
    }
    return ret;
  }
};
