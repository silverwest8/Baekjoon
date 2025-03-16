import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                index = 0;
                answer += " ";
                continue;
            }
            if (index % 2 == 0) {
                answer += Character.toString(s.charAt(i)).toUpperCase();
            } else {
                answer += Character.toString(s.charAt(i)).toLowerCase();
            }
            index++;
        }
        return answer;
    }
}