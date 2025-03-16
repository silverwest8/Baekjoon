import java.util.*;
class Solution {
    public String solution(String s, int n) {
        String answer = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ' ') {
                answer += " ";
                continue;
            }
            if (c >= 'a' && c <= 'z') {
                char a = 'a';
                int n2 = 97;
                if (c + n > 'z') {
                    answer += Character.toString((char)(c + n - 26));
                } else {
                    answer += Character.toString(c + n);
                }
            } else if (c >= 'A' && c <= 'Z') {
                char A = 'A';
                if (c + n > 'Z') {
                    answer += Character.toString((char)(c + n - 26));
                } else {
                    answer += Character.toString(c + n);
                }
            }
            
        }
        return answer;
    }
}