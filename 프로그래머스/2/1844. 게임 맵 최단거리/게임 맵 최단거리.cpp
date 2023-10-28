#include<vector>
#include<queue>
#include<iostream>

const int xdir[4] = {0, 1, 0, -1};
const int ydir[4] = {1, 0, -1, 0};

int solution(std::vector<std::vector<int> > maps) {
    int N = maps.size();
    int M = maps[0].size();
    std::vector<std::vector<int> > visited(N, std::vector<int>(M, false));
    
    int answer = -1;
    
    std::queue<int> q;
    std::vector<int> save(N*M, -1);
    
    q.push(0);
    visited[0][0] = true;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        
        int x = temp/M;
        int y = temp%M;
        
        for (int k = 0; k < 4; k++) {
            int i = x+xdir[k];
            int j = y+ydir[k];
            if (i < N && i >= 0 && j < M && j >= 0) {
                if (!visited[i][j] && maps[i][j] == 1) {
                    visited[i][j] = true;
                    q.push(i*M+j);
                    save[i*M+j] = temp;
                }
            }
        }
    }
    
    // for (int i = 0; i < save.size(); i++) {
    //     std::cout << save[i] << " ";
    //     if ((i+1)%M == 0) {
    //         std::cout<<"\n";
    //     }
    // }
    // std::cout<<"\n";
    
    if (save[N*M-1] != -1) {
        answer = 0;
        int temp = N*M-1;
        while(temp != -1) {
            temp = save[temp];
            answer++;
        }
    }
    return answer;
}