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
#include <queue>
#include <stack>
#include <array>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)(x).size())
#define A(x) (x).begin(), (x).end()
void _read();

using i64 = long long;
const int INF = 1e9 + 45;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), dp(n + 1), ac(n + 1, -INF);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++) {
    dp[i] = max(dp[i - 1], ac[a[i]] + i + 1);
    ac[a[i]] = max(ac[a[i]], dp[i - 1] - i);
  }

  cout << dp[n] << "\n";

}

int main() { _read();
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}

void _read() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt","r",stdin);
#endif
}
