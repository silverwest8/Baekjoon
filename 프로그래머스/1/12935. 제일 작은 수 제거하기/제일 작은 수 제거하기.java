import java.util.*;
class Solution {
    public int[] solution(int[] arr) {
        if (arr.length == 1) {
            return new int[] {-1};
        }
        int[] copy = Arrays.copyOf(arr, arr.length);
        Arrays.sort(copy);
        int min = copy[0];
        
        int[] answer = new int[arr.length-1];
        
        int idx = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != min) {
                answer[idx++] = arr[i];
            }
        }
        return answer;
    }
}