import java.util.*;
class Solution {
    public int findParent(int[] parents, int x) {
        if (parents[x] == x) {
            return x;
        }
        int root = findParent(parents, parents[x]);
        parents[x] = root;
        return root;
    }
    public void unionParent(int[] parents, int x, int y) {
        if (x < y) {
            parents[y] = x;
        } else {
            parents[x] = y;
        }
    }
    public int solution(int n, int[][] costs) {
        int answer = 0;
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        int[] parents = new int[n];
        for (int i = 0; i < parents.length; i++) {
            parents[i] = i;
        }
        int count = 0;
        for(int[] cost: costs) {
            if (findParent(parents, cost[0]) != findParent(parents, cost[1])) {
                // 루트가 다르면
                unionParent(parents, findParent(parents, cost[0]), findParent(parents, cost[1]));
                answer += cost[2];
                count++;
                if(count == n-1) {
                    break;
                }
            }
        }
        return answer;
    }
}