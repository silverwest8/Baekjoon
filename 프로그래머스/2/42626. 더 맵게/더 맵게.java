import java.util.*;

public class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int num: scoville) {
            pq.add(num);
        }
        while(answer != -1) {
            if (pq.peek() >= K) {
                break;
            }
            if (pq.size() >= 2) {
                int first = pq.poll();
                int second = pq.poll();
                // System.out.println("first : " +first);
                // System.out.println("second : " +second);
                if (first < K) {
                    pq.add(first + second*2);
                    // System.out.println(scoville[answer+1]);
                    answer++;
                }
            } else {
                if (pq.peek() < K) {
                    answer = -1;
                }
            }
        }
        
        return answer;
    }
}

// import java.util.*;
// import java.util.stream.*;

// public class Solution {
//     public int solution(int[] scoville, int K) {
//         int answer = 0;
//         List<Integer> list = Arrays.stream(scoville).boxed().collect(Collectors.toList());
//         PriorityQueue<Integer> queue = new PriorityQueue<>(list);
        
//         Integer minScoville = queue.poll();
//         while (minScoville < K) {
//             Integer minScoville2 = queue.poll();
//             if (minScoville2 == null) {
//                 return -1;
//             }
//             int newScoville = minScoville + minScoville2 * 2;
//             queue.offer(newScoville);
//             minScoville = queue.poll();
//             answer++;
//         }
//         return answer;
//     }
// }