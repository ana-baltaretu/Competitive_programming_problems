package Reducing_Dishes_1402;

import java.util.Arrays;

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int mx = 0;
        Arrays.sort(satisfaction);
        int N = satisfaction.length;
        int[][] dp = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (i > 0) {
                    if (i == j)
                        dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = Integer.max(dp[i - 1][j - 1], dp[i][j - 1]);
                }
                dp[i][j] += satisfaction[j] * (i + 1);
                mx = Integer.max(dp[i][j], mx);
            }
        }
        return mx;
    }
}
