import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        // boolean[] check = new boolean[routes.length];
        Arrays.sort(routes, (a, b) -> Integer.compare(a[1], b[1]));
        int now = -30000;
        for (int i = 0; i < routes.length; i++) {
            // if (check[i]) {
            //     continue;
            // }
            if (now < routes[i][0]) {
                answer++;
                now = routes[i][1];
            }
            // for (int j = i+1; j < routes.length; j++) {
            //     if (routes[j][0] <= routes[i][1]) {
            //         check[j] = true;
            //     } else {
            //         break;
            //     }
            // }
            // answer++;
            // check[i] = true;
        }
        
        return answer;
    }
}