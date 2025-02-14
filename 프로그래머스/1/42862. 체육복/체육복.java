import java.util.*;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        Arrays.sort(lost);
        Arrays.sort(reserve);
        
        HashSet<Integer> reserve1 = new HashSet<>();
        HashSet<Integer> lost1 = new HashSet<>();

        for(int num: reserve) {
            reserve1.add(num);
        }
        
        for(int num: lost) {
            lost1.add(num);
        }
        HashSet<Integer> common = new HashSet<>(reserve1);
        common.retainAll(lost1);
        
        reserve1.removeAll(common);
        lost1.removeAll(common);
        
        HashSet<Integer> all = new HashSet<>(reserve1);
        for (int num: lost1) {
            all.add(num);
        }
        
        for (int num: lost1) {
            if (reserve1.contains(num-1)) {
                answer+=2;
                reserve1.remove(num-1);
                continue;
            }
            if (reserve1.contains(num+1)) {
                answer+=2;
                reserve1.remove(num+1);
                continue;
            }
        }
        answer+=reserve1.size();
        answer+=(n-all.size());
        
        return answer;
    }
}