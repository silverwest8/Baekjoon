import java.util.*;

class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        String s = String.valueOf(x);
        int sum = Arrays.stream(s.split("")).mapToInt(Integer::parseInt).sum();
        answer = x % sum == 0;
        return answer;
    }
}
