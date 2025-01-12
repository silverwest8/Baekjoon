class Solution {

    int[] check;
    
    void dfs(int k, int[][] computers) {
        check[k] = 1;
        for (int i = 0; i < computers.length; i++) {
            if (check[i] == 0 && k != i && computers[k][i] == 1) {
                dfs(i, computers);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        check = new int[computers.length];
        for (int i = 0; i < computers.length; i++) {
            check[i] = 0;
        }
        for (int i = 0; i < computers.length; i++) {
            if (check[i] == 0) {
                dfs(i, computers);
                answer++;
            }
        }
        
        return answer;
    }
}
