template<typename T>
struct segment_tree {
      int n;
      vector<T> tree;
      void build(const vector<int> &eu) {
            n = sz(eu);
            tree = vector<T>(n << 1);
            for( int i = 0; i < n; i++) {
                  tree[i+n] = eu[i];
            }
            for( int i = n-1; i > 0; i--) {
                  tree[i] = tree[( i << 1 )] + tree[( i << 1 ) | 1];
            }
      }
      void update( int p, int x ) {
            for( tree[p += n] = x; p > 1; p >>= 1 ) {
                  tree[p >> 1] = tree[p] + tree[p^1];
            }
      };
      T qry( int l, int r ) {
            T res = 0;
            for( l += n, r += n + 1; l < r; l >>= 1, r >>= 1 ) {
                  if(l&1) res += tree[l++];
                  if(r&1) res += tree[--r];
            }
            return res;
      };
};
