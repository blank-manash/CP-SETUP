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
#define UNI(x) sort(A(x)); (x).erase(unique(A(x)),(x).end())
void _read();

using i64 = long long;
const int INF = 1e9 + 49;

void solve() {

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
