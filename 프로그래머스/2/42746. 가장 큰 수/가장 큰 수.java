import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] str = new String[numbers.length];
        for(int i = 0; i < numbers.length; i++) {
            str[i] = Integer.toString(numbers[i]);
        }
        // Arrays.sort(str);
        Arrays.sort(str, (a, b) -> (b + a).compareTo(a + b));
        for(int i = 0; i < str.length; i++) {
            answer += str[i];
        }
        
        return answer.charAt(0) == '0' ? "0" : answer;
    }
}