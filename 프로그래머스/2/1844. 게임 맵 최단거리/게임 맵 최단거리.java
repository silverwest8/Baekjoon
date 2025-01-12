import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int n = maps.length-1;
        int m = maps[0].length-1;

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        Deque<int[]> deque = new ArrayDeque<>();
        deque.addLast(new int[]{0, 0, 1});

        while (!deque.isEmpty()) {
            int[] current = deque.removeFirst();
            int i = current[0];
            int j = current[1];
            int count = current[2];

            if (i == n && j == m) {
                return count; // 목적지에 도달한 경우 최단거리 반환
            }

            for (int dir = 0; dir < 4; dir++) {
                int k = i + dx[dir];
                int l = j + dy[dir];

                if (k >= 0 && k <= n && l >= 0 && l <= m && maps[k][l] == 1) {
                    maps[k][l] = 0; // 방문한 위치는 재방문하지 않도록 표시
                    deque.addLast(new int[]{k, l, count + 1});
                }
            }
        }

        return -1; // 목적지에 도달하지 못한 경우
    }
}



// class Solution {
//     int n;
//     int m;
//     int min;
//     boolean possible;
//     boolean[][] check;
    
//     void dfs(int count, int i, int j, int[][] maps) {
//         check[i][j] = true;
//         if (i == n && j == m) {
//             possible = true;
//             if (min > count) {
//                 min = count;
//             }
//         }
//         if (i+1 < maps.length && maps[i+1][j] == 1 && !check[i+1][j]) {
//             dfs(count+1, i+1, j, maps);
//         }
//         if (j+1 < maps[0].length && maps[i][j+1] == 1 && !check[i][j+1]) {
//             dfs(count+1, i, j+1, maps);
//         }
//         if (i-1 >= 0 && maps[i-1][j] == 1 && !check[i-1][j]) {
//             dfs(count+1, i-1, j, maps);
//         }
//         if (j-1 >= 0 && maps[i][j-1] == 1 && !check[i][j-1]) {
//             dfs(count+1, i, j-1, maps);
//         }
//         check[i][j] = false;
//     }
//     public int solution(int[][] maps) {
//         int answer = 0;
//         n = maps.length-1;
//         m = maps[0].length-1;
//         min = maps.length*maps[0].length;
//         check = new boolean[maps.length][maps[0].length];
        
//         dfs(1, 0, 0, maps);
//         answer = min;
//         if (!possible) {
//             answer = -1;
//         }
        
//         return answer;
//     }
// }