import java.util.*;
class Solution {
    public int solution(int N, int number) {
        ArrayList<HashSet<Integer>> dp = new ArrayList<>();
        
        for (int i = 0; i <= 8; i++) {
            dp.add(new HashSet<Integer>());
        }
        int temp = N;
        for (int i = 1; i <= 8; i++) {
            dp.get(i).add(temp);
            temp = temp*10+N;
        }
        
        for(int i = 1; i <= 8; i++) {
            for (int j = 1; j < i; j++) {
                for (int num: dp.get(j)) {
                    for (int num2: dp.get(i-j)) {
                        dp.get(i).add(num+num2);
                        dp.get(i).add(num-num2);
                        dp.get(i).add(num*num2);
                        if (num2 != 0) dp.get(i).add(num/num2);
                    }
                }
            }
            if (dp.get(i).contains(number)) {
                return i;
            }
        }
        return -1;
    }
}