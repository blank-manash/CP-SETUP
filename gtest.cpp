/*
 * Author: Manash Baul <mximpaid@gmail.com>
 * @param: The deeper you go, the more still you become.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)(x).size())
#define A(x) (x).begin(), (x).end()
void _read();

struct Compressed {
  vector<string> original;
  Compressed(const vector<string> &vec) : original(vec) {
    sort(A(original));
    auto it = unique(A(original));
    original.erase(it, original.end());
  }
  int fw_map(string x) {
    auto it = lower_bound(A(original), x);
    if (it == original.end()) return -1;
    if (*it != x) return -1;
    return int(it - original.begin());
  }

  string back_map(int idx) {
    assert(idx >= 0 && idx < original.size());
    return original.at(idx);
  }

  int size() {
    return original.size();
  }
};

struct DSU {
  int n;
  vector<int> p, s;
  DSU(int _n) {
    n = _n;
    p = vector<int>(n);
    s = vector<int>(n, 1);
    iota(A(p), 0);
  }
  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }
  void combine(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    p[b] = a;
    s[a] += s[b];
  }
  bool isSame(int x, int y) {
    return find(x) == find(y);
  }
};

using t3 = tuple<int, int, int>;

struct Graph {
  int n;
  vector<t3> edges;
  Graph() {
    int m;
    cin >> m;
    vector<tuple<string, string, int>> string_edges;
    vector<string> string_nodes;
    while(m--) {
      string a, b;
      int w;
      cin >> a >> b >> w;
      string_nodes.push_back(a);
      string_nodes.push_back(b);
      string_edges.emplace_back(a, b, w);
    }
    Compressed comp = Compressed(string_nodes);
    n = comp.size();
    // Create edges
    for(const auto &[a, b, w] : string_edges) {
      int x = comp.fw_map(a);
      int y = comp.fw_map(b);
      edges.emplace_back(w, x, y);
    }
  }
  void printMst() {
    sort(A(edges));
    DSU dsu = DSU(n);
    int answer = 0;
    for(const auto &[w, x, y] : edges) {
      if (!dsu.isSame(x, y)) {
        dsu.combine(x, y);
        answer += w;
      }
    }
    for(int i = 1; i < n; ++i) {
      if (dsu.find(i) != dsu.find(0)) {
        cout << "Impossible\n";
        return;
      }
    }
    cout << answer << "\n";
  }
};

int main() { _read();
  int T; cin >> T;
  for(int t = 1; t <= T; ++t) {
    cin.ignore();
    cout << "Case " << t << ": ";
    Graph().printMst();
  }
}

void _read() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt","r",stdin);
#endif
}
