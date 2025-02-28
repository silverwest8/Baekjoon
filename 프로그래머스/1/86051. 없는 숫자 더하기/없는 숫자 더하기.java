import java.util.*;
import java.util.stream.Collectors;
class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        List<Integer> list = Arrays.stream(numbers).boxed().collect(Collectors.toList());
        ArrayList list2 = new ArrayList<>(list);
        for (int i = 0; i < 10; i++) {
            if (!list2.contains(i)) {
                answer += i;
            }
        }
        return answer;
    }
}