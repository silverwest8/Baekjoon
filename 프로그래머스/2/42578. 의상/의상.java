import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> hm = new HashMap<>();
        for (int i = 0; i < clothes.length; i++) {
            String key = clothes[i][1];
            if (!hm.containsKey(key)) {
                hm.put(key, 1);
            } else {
                hm.put(key, hm.get(key)+1);
            }
        }

        Iterator<Integer> it = hm.values().iterator();
        while(it.hasNext()) {
            answer *= it.next().intValue()+1;
        }
        return answer-1;
    }

}