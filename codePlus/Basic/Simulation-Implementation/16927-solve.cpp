#include <iostream>
#include <algorithm>

using namespace std;
 
int v[301][301];
int N,M,R;
 
//오, 아, 왼, 위
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
 
void rotate(int k, int len){
    int r = R%len;			//len은 박스의 총 칸 수
    for(int l = 0; l<r; l++){   //r칸 전진
        int startVal = v[k][k];
        int r = k;
        int c = k;
        int k = 0;
        while(k<4){
            int nr = r + dr[k];     //map[nr][nc]는 옮길 대상임 (map[r][c]로 옮겨야 함)
            int nc = c + dc[k];
            if(nr==k && nc==k) break;
            if(k<=nr && nr<N-k && k<=nc && nc<M-k){
                //차례로 시계 반대방향으로 옮김
                v[r][c] = v[nr][nc];
                r = nr;
                c = nc;
            }
            else{       //다음에 옮길 칸이 배열 범위 넘어가버리면 해당 라인은 다 옮긴거라서 k 증가
                k++;
            }
        }
        v[k+1][k] = startVal; //처음에 시작지점 빼놨던거 마지막에 빈 자리에 넣어줌.   
    }   
}
 
int main(){
    
    cin >> N >> M >> R;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> v[i][j];
        }
    }
    int n=N, m=M;
    for(int i = 0; i < min(N,M)/2; i++){ //반복문 1번에,  박스 1개가 R만큼 전진함
        rotate(i, 2*n + 2*m -4);
        n-=2;	//박스 안으로 들어갈때마다 가로,세로 2씩 줄어듦.
        m-=2;
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << v[i][j] << " ";
        }cout <<"\n";
    }
    
    
    
    return 0;
}