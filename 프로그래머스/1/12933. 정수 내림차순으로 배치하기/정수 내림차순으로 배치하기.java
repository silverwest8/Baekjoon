import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = String.valueOf(n);
        String S = "";
        // ArrayList<String> list = new ArrayList<String>();
        // for (int i = 0; i < s.length(); i++) {
        //     char c = s.charAt(i);
        //     list.add(String.valueOf(c));
        // }
        ArrayList<String> list = new ArrayList(Arrays.asList(s.split("")));
        list.sort(Comparator.reverseOrder());
        // for (int i = 0; i < list.size(); i++) {
        //     S = S + list.get(i);
        // }
        StringBuilder sb = new StringBuilder();
        for (String l : list) {
            sb.append(l);
        }
        // answer = Long.valueOf(S);
        answer = Long.valueOf(sb.toString());
        return answer;
    }
}