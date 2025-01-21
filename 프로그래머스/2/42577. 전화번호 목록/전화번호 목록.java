import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        // HashMap<String, String> hm = new HashMap<>();
        // for (int i = 0; i < phone_book.length; i++) {
        //     for (int j = 0; j < phone_book[i].length(); j++) {
        //         if (hm.containsKey(phone_book[i].substring(0, j+1))) {
        //             return false;
        //         }
        //         hm.put(phone_book[i].substring(0, j+1), phone_book[i]);
        //     }   
        // }
        Arrays.sort(phone_book);
        for (int i = 0; i < phone_book.length-1; i++) {
            if (phone_book[i+1].startsWith(phone_book[i])) {
                return false;
            }
        }

        return answer;
    }
}