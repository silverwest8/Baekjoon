import java.util.*;

public class Solution {
    public Deque<Integer> solution(int []arr) {
        int[] answer = {};
        Deque<Integer> deque = new ArrayDeque<>();
        
        for (int i = 0; i < arr.length; i++) {
            if (deque.size() == 0 || deque.peekLast() != arr[i]) {
                deque.addLast(arr[i]);
            }
        }
    
        return deque;
    }
}

// import java.util.*;
// import java.util.stream.*;;

// public class Solution {
//     public int[] solution(int []arr) {
//         List<Integer> list = new ArrayList<>();
//         list.add(arr[0]);

//         for (int i = 1; i < arr.length; i++) {
//             if (arr[i] != arr[i - 1]) {
//                 list.add(arr[i]);
//             }
//         }

//         int[] answer = list.stream().mapToInt(Integer::intValue).toArray();
//         return answer;
//     }
// }