template<typename T = string> class String_Hash {
      int n;
      T s;
      vector<i64> mod = {(i64) 1e9 + 7, (i64) 1e9 + 2667};
      vector<i64> A = {101, 737};
      array<vector<i64>,2> H,P;
      void process(vector<i64> &h, vector<i64> &p, i64 X, i64 MOD) {
            h[0] = s[0];
            p[0] = 1;
            for(int i = 1; i < n; i++) {
                  h[i] = (h[i - 1] * X) % MOD + s[i];
                  p[i] = (p[i - 1] * X) % MOD;
                  h[i] %= MOD;
            }
      }
      i64 get(int x, int i, int j) {
            i64 ret = H[x][j];
            i64 MOD = mod[x];
            if(i > 0) {
                  i64 y = (H[x][i - 1] * P[x][j - i + 1]) % MOD;
                  ret -= y;
                  if(ret < 0)
                        ret += MOD;
            }
            return ret;
      }
public:
      String_Hash(T _S) : s(_S), n((int) _S.size()) {
            H[0] = H[1] = P[1] = P[0] = vector<i64>(n);
            for(int x : {0, 1})
                  process(H[x], P[x], A[x], mod[x]);
      }
      pair<i64,i64> get(int i , int j) {
            assert(i <= j);
            return make_pair(get(0, i, j), get(1, i, j));
      }
      pair<i64,i64> get() { return get(0, n - 1); };
};
