class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        long[][] map = new long[n][m];
        for (int i = 0; i < puddles.length; i++) {
            map[puddles[i][1]-1][puddles[i][0]-1] = -1;
        }
        map[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == -1) {
                    continue;
                }
                long temp = 0;
                long temp2 = 0;
                if (i-1 >= 0 && map[i-1][j] != -1) {
                    temp = map[i-1][j];
                }
                if (j-1 >= 0 && map[i][j-1] != -1) {
                    temp2 = map[i][j-1];
                }
                map[i][j] = (temp + temp2) % 1000000007;
                map[0][0] = 1;
            }
        }
        answer = (int)map[n-1][m-1] % 1000000007;
        return answer;
    }
}