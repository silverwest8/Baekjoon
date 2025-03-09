import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        String[] str = s.split("");
        Arrays.sort(str, (a, b) -> b.compareTo(a));
        answer = String.join("", str);
        return answer;
    }
}