import java.util.*;
import javafx.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        Deque<Pair<String, Integer>> deque = new ArrayDeque<>();
        deque.addLast(new Pair<>(begin, 0));
        
        while(!deque.isEmpty()) {
            Pair<String, Integer> now = deque.removeFirst();
            String f = now.getKey();
            Integer s = now.getValue();
            
            if (f.equals(target)) {
                System.out.println("equals");
                return s;
            }
            
            for (String word: words) {
                int diff = 0;
                for (int i = 0; i < word.length(); i++) {
                    if (word.charAt(i) != f.charAt(i)) {
                        diff++;
                    }
                }
                if (diff == 1 && s+1 <= words.length) {
                    deque.addLast(new Pair<>(word, s+1));
                }
            }
            
        }
        return 0;
    }
}