import java.util.*;

class Solution {
    class Truck {
        int weight;
        int move;

        public Truck(int weight) {
            this.weight = weight;
            this.move = 1;
        }

        public void moving() {
            move++;
        }
    }

    public int solution(int bridgeLength, int weight, int[] truckWeights) {
        Queue<Truck> waitQ = new LinkedList<>();
        Queue<Truck> moveQ = new LinkedList<>();

        for (int t : truckWeights) {
            waitQ.offer(new Truck(t));
        }

        int answer = 0;
        int curWeight = 0;

        while (!waitQ.isEmpty() || !moveQ.isEmpty()) {
            answer++;

            if (moveQ.isEmpty()) {
                Truck t = waitQ.poll();
                curWeight += t.weight;
                moveQ.offer(t);
                continue;
            }

            for (Truck t : moveQ) {
                t.moving();
            }

            if (moveQ.peek().move > bridgeLength) {
                Truck t = moveQ.poll();
                curWeight -= t.weight;
            }

            if (!waitQ.isEmpty() && curWeight + waitQ.peek().weight <= weight) {
                Truck t = waitQ.poll();
                curWeight += t.weight;
                moveQ.offer(t);
            }
        }

        return answer;
    }
}

// import java.util.*;

// class Solution {
//     class Truck {
//         int weight;
//         int length;
        
//         public Truck (int weight, int length) {
//             this.weight = weight;
//             this.length = length;
//         }
//         @Override
//         public String toString() {
//             return "Truck{weight=" + weight + ", length=" + length + "}";
//         }
//     }
//     public int solution(int bridge_length, int weight, int[] truck_weights) {
//         int answer = 0;
//         Deque<Truck> bridge = new ArrayDeque<>();
//         Deque<Integer> weights = new ArrayDeque<>();
//         for (int num : truck_weights) {
//             weights.addLast(num);
//         }
        
//         // Integer now = weights.removeFirst();
//         // bridge.addLast(new Truck(now.intValue, 1));
//         // answer++;

//         // while(!(bridge.isEmpty() && weights.isEmpty())) {
//         while (answer < 10) {
//             System.out.println();
//             System.out.println(answer);
//             System.out.println("bridge : "+bridge);
//             System.out.println("weights : "+weights);
//             // 다리 위에 있는 트럭이 bridge_length를 지났으면 빼내기
//             if (!bridge.isEmpty()) {
//                 Truck t = bridge.peekFirst();
//                 System.out.println("t : "+t);
//                 if (t.length >= bridge_length) {
//                     bridge.removeFirst();
//                 } else {
//                     t.length++;
//                 }
//             }
            
            
            
//             // 대기 트럭에서 하나 빼서 bridge_length가 안넘었고 무게가 weight이하이면 다리로 보내기/아니면 대기
//             if (!weights.isEmpty()) {
//                 int temp = weights.peekFirst().intValue();
//                 int sum = 0;
//                 for (Truck truck: bridge) {
//                     sum+=truck.weight;
//                 }
//                 System.out.println(bridge_length >= bridge.size()+1);
//                 System.out.println(sum);
//                 System.out.println(temp);
//                 System.out.println(sum+temp <= weight);

//                 if (bridge_length >= bridge.size()+1 && sum+temp <= weight) {
//                     Integer add = weights.removeFirst();
//                     bridge.addLast(new Truck(add, 1));
//                 }
//             }
            
            
//             answer++;
//             System.out.println(answer);
//             System.out.println("bridge : " + bridge);
//             System.out.println("weights : " + weights);
//             // break;
//         }
//         return answer;
//     }
// }