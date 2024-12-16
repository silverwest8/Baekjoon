import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        
        ArrayList<Integer> array = new ArrayList<Integer>(Arrays.stream(absolutes).boxed().collect(Collectors.toList()));
        for (int i = 0; i < array.size(); i++) {
            if (signs[i]) {
                answer+=array.get(i);
            } else {
                answer-=array.get(i);
            }
        }
        
        return answer;
    }
}
