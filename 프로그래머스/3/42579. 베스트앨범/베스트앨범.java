import java.util.HashMap;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Map;
import java.util.Collections;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Object> genresMap = new HashMap<String, Object>();      //<장르, 곡 정보> 
        HashMap<String, Integer> playMap = new HashMap<String, Integer>(); //<장르, 총 장르 재생수>
        ArrayList<Integer> resultAL = new ArrayList<Integer>();

        for(int i = 0; i < genres.length; i++){
            String key = genres[i];
            HashMap<Integer, Integer> infoMap;       // 곡 정보 : <곡 고유번호, 재생횟수>

            if(genresMap.containsKey(key)){
                 infoMap = (HashMap<Integer, Integer>)genresMap.get(key);
            }
            else {
                infoMap = new HashMap<Integer, Integer>();
            }

            infoMap.put(i, plays[i]);
            genresMap.put(key, infoMap);

            //재생수
            if(playMap.containsKey(key)){
                playMap.put(key, playMap.get(key) + plays[i]);
            }
            else {
                playMap.put(key, plays[i]);
            }
        }

        int mCnt = 0;
        Iterator it = sortByValue(playMap).iterator();

        while(it.hasNext()){
            String key = (String)it.next();
            Iterator indexIt = sortByValue((HashMap<Integer, Integer>)genresMap.get(key)).iterator();
            int playsCnt = 0;

            while(indexIt.hasNext()){
                resultAL.add((int)indexIt.next());
                mCnt++;
                playsCnt++;
                if(playsCnt > 1) break;
            }
        }

        int[] answer = new int[resultAL.size()];

        for(int i = 0; i < resultAL.size(); i++){
            answer[i] = resultAL.get(i).intValue();
        }

        return answer;
    }

    private ArrayList sortByValue(final Map map){
        ArrayList<Object> keyList = new ArrayList();
        keyList.addAll(map.keySet());

        Collections.sort(keyList, new Comparator(){
            public int compare(Object o1, Object o2){
                Object v1 = map.get(o1);
                Object v2 = map.get(o2);

                return ((Comparable) v2).compareTo(v1);
            }
        });

        return keyList;
    }
}
// import java.util.*;
// class Solution {
//     public int[] solution(String[] genres, int[] plays) {
//         int[] answer = {};
//         HashMap<String, Integer> hm = new HashMap<>();
//         for (int i = 0; i < genres.length; i++) {
//             if (!hm.containsKey(genres[i])) {
//                 hm.put(genres[i], plays[i]);
//                 ArrayList<Integer> list = new ArrayList<>();
//                 list.add(plays[i]);
//             } else {
//                 hm.put(genres[i], hm.get(genres[i])+plays[i]);
//             }
//         }
        
//         int max = 0;
//         String maxs = "";
//         int idx = 0;
//         ArrayList<Integer> ans = new ArrayList<>();
//         // int save = -1;
//         int limit2 = 0;
//         while(idx < 4) {
//             System.out.println("\nidx : " + idx);
//             // 속한 노래가 많이 재생된 장르 고르기
//             Iterator<String> it = hm.keySet().iterator();
//             while(it.hasNext()) {
//                 String tmp = it.next();
//                 int temp = hm.get(tmp);
//                 if (max < temp) {
//                     max = temp;
//                     maxs = tmp;
//                 }
//             }
            
//             int tempMax = -1;
//             int tempMaxIdx = -1;
            
//             for (int i = 0; i < plays.length; i++) {
//                 if (genres[i].equals(maxs)) {
//                     if (tempMax < plays[i] && !ans.contains(i)) {
//                         tempMax = plays[i];
//                         tempMaxIdx = i;
//                     }
//                     if (ans.contains(i)) {
//                         hm.remove(maxs);
//                     }
//                 }
//             }
            
//             System.out.println("tempMaxIdx : " + tempMaxIdx);
//             System.out.println("limit2 : " + limit2);
//             if (tempMaxIdx != -1 && limit2 < 2) {
//                 ans.add(tempMaxIdx);
//                 System.out.println("ans : " + tempMaxIdx);
//                 limit2++;
//             }
            
//             if (limit2 >= 2) {
//                 System.out.println("remove : " + maxs);
//                 hm.remove(maxs);
//                 limit2 = 0;
//             }
//             idx++;
//             max = 0;
//         }
        
//         answer = new int[ans.size()];
//         for (int i = 0; i < ans.size(); i++) {
//             answer[i] = ans.get(i);
//         }
        
//         return answer;
//     }
// }