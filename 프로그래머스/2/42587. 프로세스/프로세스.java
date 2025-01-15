import java.util.*;

class Solution {
    class Node implements Comparable<Node>{
        int pri;
        int loc;
        Node (int pri, int loc) {
            this.pri = pri;
            this.loc = loc;
        }
        @Override
        public int compareTo(Node n) {
            return this.pri - n.pri;
        }
    }
        
        
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Deque<Node> deque = new ArrayDeque<>();
        Integer[] priorities2 = new Integer[priorities.length];
        for (int i = 0; i < priorities.length; i++) {
            deque.addLast(new Node(priorities[i], i));
            priorities2[i] = priorities[i];
        }        
        Arrays.sort(priorities2, Collections.reverseOrder());
        
        int idx = 0;
        while(idx < priorities2.length) {
            Node now = deque.removeFirst();
            if (now.pri == priorities2[idx]) {
                idx++;
                if (now.loc == location) {
                    answer = idx;
                    break;
                }
            } else {
                deque.addLast(now);
            }    
        }

        return answer;
    }
}