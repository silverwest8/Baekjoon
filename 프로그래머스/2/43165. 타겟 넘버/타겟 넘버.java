import java.util.*;

class Solution {
    static int how = 0;
    
    public void dfs(int count, int now, int[] numbers, int target) {
        if (count == numbers.length) {
            if (now == target) {
                how++;
            }
            return;
        }
        dfs(count+1, now+numbers[count], numbers, target);
        dfs(count+1, now-numbers[count], numbers, target);    
    }
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(0, 0, numbers, target);
        answer = how;
        return answer;
    }
}