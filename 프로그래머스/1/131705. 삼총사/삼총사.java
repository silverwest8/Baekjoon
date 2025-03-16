import java.util.*;
class Solution {
    int answer = 0;
    void dfs(int[] number, ArrayList<Integer> list, int index) {
        if (list.size() == 3) {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += list.get(i);
            }
            System.out.println();
            if (sum == 0) {
                answer++;
            }
        }
        for (int i = index; i < number.length; i++) {
            list.add(number[i]);
            dfs(number, list, i+1);
            list.remove(list.size() - 1);
        }
    }
    public int solution(int[] number) {
        ArrayList<Integer> list = new ArrayList<>();;
        dfs(number, list, 0);
        return answer;
    }
}