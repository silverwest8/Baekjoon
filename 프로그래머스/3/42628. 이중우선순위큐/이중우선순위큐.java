import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {};
        answer = new int[2];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(Comparator.reverseOrder()); // 최대 힙
        
        for (int i = 0; i < operations.length; i++) {
            String[] temp = operations[i].split(" ");
            String command = temp[0];

            if (command.equals("I")) { // 숫자 삽입
                Integer num = Integer.valueOf(temp[1]);

                pq.add(num);
                pq2.add(num);
            } else if (command.equals("D")) { // 숫자 삭제
                String value = temp[1];
                
                if (value.equals("1")) { // 최댓값 삭제
                    if (!pq2.isEmpty()) {
                        pq.remove(pq2.poll());
                    }
                    
                } else if (value.equals("-1")) { // 최솟값 삭제
                    if (!pq.isEmpty()) {
                        pq2.remove(pq.poll());
                    }
                }
            }
        }
        // 결과 계산
        if (pq.isEmpty() || pq2.isEmpty()) {
            answer[0] = 0;
            answer[1] = 0;
        } else {
            answer[0] = pq2.peek(); // 최대값
            answer[1] = pq.peek(); // 최소값
        }

        return answer;
    }
}