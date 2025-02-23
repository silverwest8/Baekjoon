import java.util.*;

class Solution {
    public int solution(int[] money) {
        int n = money.length;
        
        // 집이 1개인 경우 예외 처리
        if (n == 1) return money[0];

        // DP 배열 초기화
        int[] dp1 = new int[n]; // 첫 번째 집 포함 (마지막 집 제외)
        int[] dp2 = new int[n]; // 첫 번째 집 제외 (마지막 집 포함)

        // 1. 첫 번째 집을 터는 경우
        dp1[0] = money[0];
        dp1[1] = Math.max(money[0], money[1]); // 0번 집 or 1번 집 중 선택
        for (int i = 2; i < n - 1; i++) { // 마지막 집 제외
            dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + money[i]);
        }

        // 2. 첫 번째 집을 안 터는 경우
        dp2[0] = 0; // 첫 번째 집을 안 털었으므로 0
        dp2[1] = money[1]; // 1번 집부터 시작
        for (int i = 2; i < n; i++) { // 마지막 집 포함
            dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + money[i]);
        }

        // 두 경우 중 최댓값 반환
        return Math.max(dp1[n - 2], dp2[n - 1]);
    }
}
