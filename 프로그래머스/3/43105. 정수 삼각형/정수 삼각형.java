import java.util.*;
class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int[][] sum = new int[triangle.length][];
        for (int i = 0; i < triangle.length; i++) {
            sum[i] = Arrays.copyOf(triangle[i], triangle[i].length);
        }
        for (int i = 1; i < triangle.length; i++) {
            for (int j = 0; j < triangle[i].length; j++) {
                if (j == 0) sum[i][j] = sum[i-1][j]+triangle[i][j];
                else if (j == triangle[i].length-1) sum[i][j] = sum[i-1][j-1]+triangle[i][j];
                else sum[i][j] = Math.max(sum[i-1][j-1]+triangle[i][j], sum[i-1][j]+triangle[i][j]);
                answer = Math.max(answer, sum[i][j]);
            }
        }
        return answer;
    }
}