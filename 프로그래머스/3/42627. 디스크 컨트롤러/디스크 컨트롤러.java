import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;

        // 작업이 요청되는 시점 기준으로 오름차순 정렬
        Arrays.sort(jobs, (o1, o2) -> o1[0] - o2[0]);

        // 작업의 소요시간 기준으로 오름차순 정렬
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);

        int jobs_index = 0; // 작업 배열 인덱스
        int finish_job = 0; // 처리 완료된 작업 개수
        int end_time = 0; // 작업 처리 완료 시간

        while(true) {
            if(finish_job == jobs.length) break; // 모든 작업을 처리했다면 종료

            // 이전 작업 처리 중 요청된 작업 add
            while(jobs_index < jobs.length && jobs[jobs_index][0] <= end_time) {
                pq.add(jobs[jobs_index++]); // 현재 시간(end_time)까지 요청된 작업을 우선순위 큐에 추가
            }

            if(!pq.isEmpty()) { // 요청된 작업이 있는 경우
                int[] job = pq.poll(); // 가장 짧은 작업을 꺼냄
                answer += end_time - job[0] + job[1]; // 작업 요청부터 종료까지 걸린 시간 추가
                end_time += job[1]; // 현재 시간 갱신 (작업 소요 시간 추가)
                finish_job++; // 완료된 작업 개수 증가
            } else { // 큐가 비어 있다면 (현재 실행할 작업이 없는 경우)
                end_time = jobs[jobs_index][0]; // 다음 요청된 작업 시간으로 이동
            }
        }

        return answer / jobs.length;
    }
}