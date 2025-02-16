import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int end = people.length -1;
        Arrays.sort(people);
        for (int i = 0; i <= end; i++) {
            if (i == end) {
                answer++;
                break;
            }
            if (people[i] + people[end] <= limit) {
                answer++;
                end--;
            } else {
                answer++;
                end--;
                i--;
            }
        }
        return answer;
    }
}