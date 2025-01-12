import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int num = nums.length / 2;
        
        HashSet<Integer> hashSet = new HashSet<>(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        
        answer = hashSet.size() < num ? hashSet.size() : num;
        
        return answer;
    }
}