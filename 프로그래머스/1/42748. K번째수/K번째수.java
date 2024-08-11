import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};

        List<Integer> answerList = new ArrayList<>();
        for (int[] command : commands) {
            int start = command[0] - 1;
            int end = command[1];
            int k = command[2] - 1;
            
            int[] subArray = Arrays.copyOfRange(array, start, end);
            Arrays.sort(subArray);
            answerList.add(subArray[k]);
        }

        answer = answerList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}