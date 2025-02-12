import java.util.*;
class Solution {
    public void add(HashSet<Integer> hs, int[][] wires, boolean[] visited) {
        for(int j = 0; j < wires.length; j++) {
            if (visited[j]) continue;
            if (hs.contains(wires[j][0])) {
                hs.add(wires[j][1]);
                visited[j] = true;
                add(hs, wires, visited);
            }
            if (hs.contains(wires[j][1])) {
                hs.add(wires[j][0]);
                visited[j] = true;
                add(hs, wires, visited);
            }
        }
    }
    public int solution(int n, int[][] wires) {
        int answer = n;
        
        for (int i = 0; i < wires.length; i++) {
            // wires[i] 를 하나씩 돌면서, wires[i][0], wires[i][1]을 기준으로 자름
            HashSet<Integer> hs1 = new HashSet<>();
            HashSet<Integer> hs2 = new HashSet<>();
            boolean[] visited1 = new boolean[n];
            boolean[] visited2 = new boolean[n];
            
            hs1.add(wires[i][0]);
            visited1[i] = true;
            for (Integer item: hs1) {
                add(hs1, wires, visited1);
            }
            
            visited2[i] = true;
            hs2.add(wires[i][1]);
            for (Integer item: hs2) {
                add(hs2, wires, visited2);
            }
            answer = Math.min(answer, Math.abs(hs1.size()-hs2.size()));
        }
        
        
        return answer;
    }
}