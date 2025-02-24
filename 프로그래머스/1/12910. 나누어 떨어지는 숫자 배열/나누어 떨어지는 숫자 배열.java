import java.util.*;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {};
        answer = Arrays.stream(arr).filter(ele -> ele % divisor == 0).toArray();
        // ArrayList<Integer> list = new ArrayList<>();
        // for (int i = 0; i < arr.length; i++) {
        //     if (arr[i] % divisor == 0) {
        //         list.add(arr[i]);
        //     }
        // }
        if (answer.length == 0) {
            return new int[] {-1};
        }
        // list to arr
        // answer = list.stream().mapToInt(Integer::intValue).toArray();
        Arrays.sort(answer);
        return answer;
    }
}