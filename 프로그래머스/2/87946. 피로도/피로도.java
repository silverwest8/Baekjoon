class Solution {
    int count = 0;
    public int solution(int k, int[][] dungeons) {
        int answer = 0;
        boolean[] visited = new boolean[dungeons.length];
        go(k, dungeons, visited, answer);
        return count;
    }
    
    public void go(int k, int[][] dungeons, boolean[] visited, int answer) {
        for (int i = 0; i < dungeons.length; i++) {
            if (!visited[i]) {
                if (dungeons[i][0] <= k) {
                    visited[i] = true;
                    count = Math.max(answer+1, count);
                    go(k-dungeons[i][1], dungeons, visited, answer+1);
                    visited[i] = false;
                }
            }
        }
    }
}