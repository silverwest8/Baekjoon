import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);

        // 배열 뒤집기
        for (int i = 0; i < citations.length / 2; i++) {
            int temp = citations[i];
            citations[i] = citations[citations.length - 1 - i];
            citations[citations.length - 1 - i] = temp;
        }

        for (int i = 0; i <= citations.length; i++) {
            if ((i == 0 || citations[i-1] >= i) && (i == citations.length || citations[i] <= i)) {
                answer = i;
            }
        }
        return answer;
    }
}