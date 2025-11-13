#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &c, int a) {
    int n = c.size();
    vector<int> dp(a + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i <= a; i++) {
      for (int j : c) {
        if (i - j >= 0) {
          dp[i] = min(dp[i], 1 + dp[i - j]);
        }
      }
    }
    return dp[a] == INT_MAX - 1 ? -1 : dp[a];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solution sol;
  cout << sol.coinChange({1, 2, 5}, 11);
  return 0;
}
