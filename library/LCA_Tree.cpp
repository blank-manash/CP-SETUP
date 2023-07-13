struct LCA_Tree {
      int n;
      vector<vector<int>> adj;
      vector<array<int,21>> up;
      vector<int> dep;
      bool init = false;
      int root = 1;
      int set_bit(int x) {
            return 31 - __builtin_clz(x);
      }
      void dfs(int u, int p, int de = 0) {
            dep[u] = de;
            up[u][0] = p;
            for(int ptr = 1; ptr < 21; ++ptr) {
                  up[u][ptr] = up[up[u][ptr - 1]][ptr - 1];
            }
            for(int v : adj[u]) {
                  if(v != p)
                        dfs(v,u,de + 1);
            }
      };
      LCA_Tree(int _n, int _root = 1) : n(_n), root(_root){
            adj = vector<vector<int>>(n + 1);
            dep = vector<int>(n + 1);
            up.resize(n + 1);
      };
      void INIT() {
            dfs(root,root,0);
      }
      void add_edge(int a, int b) {
            adj[a].push_back(b); 
            adj[b].push_back(a);
      }
      
      int LCA(int a, int b) {
            if(!init) {
                  init = true;
                  INIT();
            }
            if(dep[a] > dep[b])
                  swap(a,b);
            int diff = dep[b] - dep[a];
            while(diff > 0) {
                  int i = set_bit(diff);
                  b = up[b][i];
                  diff ^= (1 << i);
            }
            while(a != b) {
                  int i = set_bit(dep[a]);
                  while(i > 0 && up[a][i] == up[b][i])
                        --i;
                  a = up[a][i];
                  b = up[b][i];
            }
            return a;
      };
      int dist(int a, int b) {
            if(!init) {
                  init = true;
                  INIT();
            }
            return dep[a] + dep[b] - 2 * dep[LCA(a,b)];
      };
};
