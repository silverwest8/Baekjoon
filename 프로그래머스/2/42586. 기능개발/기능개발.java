import java.util.*;

// class Solution {

//     public int[] solution(int[] progresses, int[] speeds) {
//         int[] answer = {};
//         ArrayList<Integer> list = new ArrayList<>();
        
//         int task = 0;
//         while (task < progresses.length) {
//             // task번째꺼가 몇칠이 지나야 100이 넘는지 확인
//             int day = Double.valueOf(Math.ceil((100-progresses[task])/speeds[task])).intValue();
//             for (int i = task; i < progresses.length; i++) {
//                 progresses[i] += speeds[i]*day;
//                 System.out.print(progresses[i]);
//                 System.out.print(" ");
//             }
//             System.out.println();
//             int count = 1;
//             for (int i = task+1; i < progresses.length; i++) {
//                 if (progresses[i] >= 100) {
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             list.add(count);
//             task += count;
//         }

//         answer = new int[list.size()];
//         for (int i = 0; i < list.size(); i++) {
//             answer[i] = list.get(i);
//         }
        
//         return answer;
//     }
// }

class Solution {

    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        
        int task = 0;
        while (task < progresses.length) {
            // 일단 더하기
            for (int j = 0; j < progresses.length; j++) {
                progresses[j] += speeds[j];
            }
            if (progresses[task] >= 100) {
                // 바로 뒤 몇번째꺼까지 100이 넘는지 확인
                int mem = task;
                for (int j = mem; j < progresses.length; j++) {
                    if (progresses[j] >= 100) {
                        mem = j;
                    } else {
                        break;
                    }
                }
                list.add(mem-task+1);
                task = mem+1;
            }
        }

        answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}