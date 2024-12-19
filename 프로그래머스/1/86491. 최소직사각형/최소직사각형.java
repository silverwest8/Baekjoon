import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        ArrayList<ArrayList<Integer>> size = Arrays.stream(sizes)
                .map(row -> IntStream.of(row)
                                     .boxed()
                                     .collect(Collectors.toCollection(ArrayList::new)))
                .collect(Collectors.toCollection(ArrayList::new));
        int max1 = 0;
        int max2 = 0;
        for (int i = 0; i < size.size(); i++) {
            if (size.get(i).get(0) < size.get(i).get(1)) {
                Integer temp = size.get(i).get(0);
                size.get(i).set(0, size.get(i).get(1));
                size.get(i).set(1, temp);
            }
            if (max1 < size.get(i).get(0)) {
                max1 = size.get(i).get(0);
            }
            if (max2 < size.get(i).get(1)) {
                max2 = size.get(i).get(1);
            }
        }
        answer = max1*max2;
        return answer;
    }
}