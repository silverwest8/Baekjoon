import java.util.*;

class Solution {
    public int solution(int[] topping) {
//         int answer = 0;
        
//         for (int i = 1; i <= topping.length; i++) {
//             HashSet<Integer> hs = new HashSet<>();
//             HashSet<Integer> hs2 = new HashSet<>();
//             for (int j = 0; j < i; j++) {
//                 hs.add(topping[j]);
//             }
//             for (int k = i; k < topping.length; k++) {
//                 hs2.add(topping[k]);
//             }
//             if (hs.size() == hs2.size()) {
//                 answer++;
//             }
//         }
        
//         return answer;
            Set<Integer> leftSet = new HashSet<>(); // 철수가 가진 토핑 종류
            Map<Integer, Integer> rightCount = new HashMap<>(); // 동생이 가진 토핑 개수
            int rightSetCount = 0; // 동생이 가진 토핑 종류 수
            int fairCuts = 0; // 공평하게 자를 수 있는 방법의 수

            // 1️⃣ 동생이 가진 토핑 개수 초기화
            for (int t : topping) {
                rightCount.put(t, rightCount.getOrDefault(t, 0) + 1);
            }
            rightSetCount = rightCount.size(); // 동생이 가진 토핑 종류 개수

            // 2️⃣ 왼쪽에서 한 칸씩 자르면서 비교
            for (int t : topping) {
                leftSet.add(t); // 철수가 토핑 추가
                rightCount.put(t, rightCount.get(t) - 1); // 동생의 해당 토핑 개수 감소

                if (rightCount.get(t) == 0) { // 해당 토핑이 동생 쪽에서 사라지면 종류 감소
                    rightSetCount--;
                }

                if (leftSet.size() == rightSetCount) { // 공평하게 나눠지는 경우
                    fairCuts++;
                }
            }

            return fairCuts;
    }
}