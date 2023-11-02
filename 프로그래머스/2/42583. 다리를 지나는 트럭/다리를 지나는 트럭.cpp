#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

int solution(int bridge_length, int weight, std::vector<int> truck_weights) {
    int answer = 0;
    int idx=0;    //차량 지목용 idx
    int sum=0;   //현재 다리에 올라와있는 차량 무게 총합
    std::queue<int> q;  //현재 다리를 건너는 트럭 체크용 큐
    
    while(1){
        
        if(idx == truck_weights.size()){  //마지막 트럭일 때
            answer += bridge_length;  //마지막 트럭이 지나는 시간 추가
            break;  
        }
        
        answer++; //시간초 증가
        int tmp = truck_weights[idx];
        
        //차가 다리를 다 건넜을 경우
        if(q.size() == bridge_length){
            sum -= q.front();  //다 건넜으니 현재 다리에 있는 차들의 무게에서 제외
            q.pop();  
        }
        
        if(sum + tmp <= weight){  //다리에 다음 차가 진입할 수 있다면
            sum += tmp;  //차량 무게 추가
            q.push(tmp);  
            idx++;  //다음 차량을 위해서
        }else{   
            q.push(0);  //진입할 수 없다면 0을 푸시해서 시간초 계산
        }
    }
    /*
    int N = truck_weights.size();
    std::deque<int> before;
    std::deque<int> ing;
    std::vector<int> after;
    
    for (int i = 0; i < truck_weights.size(); i++) {
        before.push_back(truck_weights[i]);
    }
    
    int now = 0;
    while(true) {
        now++;
        int sum = 0;
        // std::cout << ing.size() << "!\n";
        for (int i = 0; i < ing.size(); i++) {
            sum += ing[i];
        }
        if (sum < weight) {
            // std::cout << before.front() << "~\n";
            ing.push_back(before.front());
            before.pop_front();
            continue;
        }
        
        // for (auto it = ing.begin(); it != ing.end(); it++) {
        //     std::cout << *it << " ";
        // }
        std::cout << "ing::\n";
        for (int i = 0; i < ing.size(); i++) {
            std::cout << ing[i] << " ";
        }
        std::cout << "\n";
        
        // std::cout << "before::\n";
        // for (int i = 0; i < before.size(); i++) {
        //     std::cout << before[i] << " ";
        // }
        // std::cout << "\n\n";
        
        
        
        if (!ing.empty()) {
            ing.pop_front();
        }
        
        std::cout << now << " now \n";
        if (ing.size() == 0 && before.size() == 0 && now != 0) {
            break;
        }
    }
    answer = now+1;
    */
    
    /*
    for (int i = 0; i < truck_weights.size(); i++) {
        before.push_back(truck_weights[i]);
    }
    
    
    int time = 0;
    ing.push_back(before.front());
    before.pop_front();
    while(after.size() < N) {
        int sum = 0;
        for (int i = 0; i < ing.size(); i++) {
            sum += ing[i];
        }
        // while (std::accumulate(ing.begin(), ing.end(), 0) < weight) {
        while (sum + before.front() < weight) {
            sum += before.front();
            ing.push_back(before.front());
            before.pop_front();
        }
        
        for (int i = 0; i < ing.size(); i++) {
            std::cout << ing[i] << " ";
        }
        std::cout << "\n";
        
        for (int i = 0; i < before.size(); i++) {
            std::cout << before[i] << " ";
        }
        std::cout << "\n\n";
        
        ing.pop_front();
        
        time++;
        if (time > 10) break;
    }
    */
    return answer;
}