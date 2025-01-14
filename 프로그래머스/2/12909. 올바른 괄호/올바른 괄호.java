import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Deque<String> deque = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                deque.addLast(Character.toString(s.charAt(i)));
            } else {
                if (deque.isEmpty()) {
                    return false;
                }
                deque.removeLast();
            }
        }

        answer = deque.isEmpty();        

        return answer;
    }
}