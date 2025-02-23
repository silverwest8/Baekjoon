import java.util.*;

class Solution {
    public int solution(String[] arr) {
        int n = arr.length / 2 + 1; // 숫자의 개수
        int[][] dpMax = new int[n][n]; // 최댓값 DP
        int[][] dpMin = new int[n][n]; // 최솟값 DP

        // 숫자 부분 초기화
        for (int i = 0; i < n; i++) {
            dpMax[i][i] = Integer.parseInt(arr[2 * i]);
            dpMin[i][i] = Integer.parseInt(arr[2 * i]);
        }

        // 길이 2 이상 구간 탐색
        for (int len = 1; len < n; len++) { // 구간 길이
            for (int i = 0; i < n - len; i++) { // 시작점
                int j = i + len; // 끝점
                dpMax[i][j] = Integer.MIN_VALUE;
                dpMin[i][j] = Integer.MAX_VALUE;

                for (int k = i; k < j; k++) { // 연산자 위치
                    String op = arr[2 * k + 1];

                    if (op.equals("+")) {
                        dpMax[i][j] = Math.max(dpMax[i][j], dpMax[i][k] + dpMax[k+1][j]);
                        dpMin[i][j] = Math.min(dpMin[i][j], dpMin[i][k] + dpMin[k+1][j]);
                    } else if (op.equals("-")) {
                        dpMax[i][j] = Math.max(dpMax[i][j], dpMax[i][k] - dpMin[k+1][j]);
                        dpMin[i][j] = Math.min(dpMin[i][j], dpMin[i][k] - dpMax[k+1][j]);
                    }
                }
            }
        }

        return dpMax[0][n-1];
    }
}
