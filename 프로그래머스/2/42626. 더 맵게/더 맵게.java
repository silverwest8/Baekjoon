import java.util.*;
import java.util.stream.*;

public class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        List<Integer> list = Arrays.stream(scoville).boxed().collect(Collectors.toList());
        PriorityQueue<Integer> queue = new PriorityQueue<>(list);
        
        Integer minScoville = queue.poll();
        while (minScoville < K) {
            Integer minScoville2 = queue.poll();
            if (minScoville2 == null) {
                return -1;
            }
            int newScoville = minScoville + minScoville2 * 2;
            queue.offer(newScoville);
            minScoville = queue.poll();
            answer++;
        }
        return answer;
    }
}