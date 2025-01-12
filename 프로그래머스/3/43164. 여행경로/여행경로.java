import java.util.*;

class Solution {
    private boolean dfs(String current, String[][] tickets, boolean[] visited, List<String> route) {
        route.add(current);

        // 모든 티켓을 사용한 경우 경로 완성
        if (route.size() == tickets.length + 1) {
            return true;
        }

        for (int i = 0; i < tickets.length; i++) {
            if (!visited[i] && tickets[i][0].equals(current)) {
                visited[i] = true;
                if (dfs(tickets[i][1], tickets, visited, route)) {
                    return true; // 유효한 경로를 찾으면 종료
                }
                visited[i] = false; // 백트래킹
            }
        }

        // 현재 경로가 유효하지 않으면 제거
        route.remove(route.size() - 1);
        return false;
    }
    public String[] solution(String[][] tickets) {
        // 티켓을 사전순으로 정렬
        Arrays.sort(tickets, (a, b) -> a[1].compareTo(b[1]));

        List<String> route = new ArrayList<>();
        boolean[] visited = new boolean[tickets.length];

        // DFS를 실행하여 경로 찾기
        dfs("ICN", tickets, visited, route);

        return route.toArray(new String[0]);
    }


}