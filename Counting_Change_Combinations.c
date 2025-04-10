#include <stdio.h>
#include <stdlib.h>
int count_change(int money, int n_coins, const int coins[n_coins]) {

  int *dp = calloc(money + 1, sizeof(int));
  dp[0] = 1;
  for (int i = 0; i < n_coins; i++) {

    for (int j = 1; j < money + 1; j++) {
      if (j - coins[i] < 0)
        continue;
      dp[j] += dp[j - coins[i]];
    }
  }
  return dp[money];
}
int main() {

  int n_coins = 3;
  int coins[3] = {5, 2, 3};
  int mine = count_change(10, n_coins, coins);
  printf("%d", mine);
  return 0;
}
