import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        Long N = n;
        String s = N.toString();
        String S = "";
        ArrayList<String> list = new ArrayList<String>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            list.add(String.valueOf(c));
        }
        list.sort(Comparator.reverseOrder());
        for (int i = 0; i < list.size(); i++) {
            S = S + list.get(i);
        }
        answer = Long.valueOf(S);
        return answer;
    }
}