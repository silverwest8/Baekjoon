// 2023. 8. 17 11:43 -
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ABS(x)        ( ((x)<0)?-(x):(x) )

int N, M, N_size, min, flag, check;
std::string N_string;
std::vector<int> ok, no, v;

// N_size 한자리씩 가장 똑같은 숫자 찾기
void DFS1(int n) {
    if (n == N_size) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            if (std::find(ok.begin(), ok.end(), k) != ok.end()) {
                v.emplace_back(k);
                DFS1(n+1);
            } else {
                if (ok[0] > k) { // 해당 값이 넣을 수 있는 모든 수보다 작은 경우
                    flag = 2;
                    v.emplace_back(ok[0]);
                    DFS1(n+1);
                } else if (ok[ok.size()-1] < k) { // 해당 값이 넣을 수 있는 모든 수보다 큰 경우
                    flag = 1;
                    v.emplace_back(ok[ok.size()-1]);
                    DFS1(n+1);
                } else { // 큰 값 작은 값 모두 있는 경우
                    int A = 0;
                    int a = ABS(ok[A] - k);
                    for (int i = A+1; i < ok.size(); i++) {
                        if (ok[i] > k) {
                            A = i-1;
                            a = ABS(ok[i-1] - k);
                            break;
                        }
                    }
                    int B = ok.size()-1;
                    int b = ABS(ok[B] - k);
                    for (int i = B-1; i >= 0; i--) {
                        if (ok[i] < k) {
                            B = i+1;
                            b = ABS(ok[i+1] - k);
                            break;
                        }
                    }
                    if (a < b) {
                        // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
                        flag = 1;
                        v.emplace_back(ok[A]); // small(1) flag
                        DFS1(n+1);
                    } else if (a > b) {
                        // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
                        flag = 2;
                        v.emplace_back(ok[B]); // big(2) flag
                        DFS1(n+1);
                    } else if (a == b) {
                        if (ok[A] != 0) {
                            flag = 1;
                            v.emplace_back(ok[A]);
                            DFS1(n+1);
                            for (int i = check; i >= n; i--) {
                                v.pop_back();
                            }
                        }

                        flag = 2;
                        v.emplace_back(ok[B]);
                        DFS1(n+1);
                        v.pop_back();
                    }
                }
            }
        } else if (flag == 1) { // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
            v.emplace_back(ok[ok.size()-1]);
            check = n;
            DFS1(n+1);
        } else if (flag == 2) { // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
            v.emplace_back(ok[0]);
            check = n;
            DFS1(n+1);
        }
    }
}

// N_size_2 -> 같은걸 넣을 수 있어도 안맞추고 하나 더 작은 수 넣어보기
void DFS1_2(int n) {
    if (n == N_size) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            if (ok[0] >= k) return;
            int A = 0;
            for (int i = A+1; i < ok.size(); i++) {
                if (ok[i] >= k) {
                    A = i-1;
                    break;
                }
                A = i;
            }
            // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
            flag = 1;
            v.emplace_back(ok[A]); // small(1) flag
            DFS1_2(n+1);
        } else if (flag == 1) { // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
            v.emplace_back(ok[ok.size()-1]);
            DFS1_2(n+1);
        }
    }
}

// N_size_2 -> 같은걸 넣을 수 있어도 안맞추고 하나 더 큰 수 넣어보기
void DFS1_3(int n) {
    if (n == N_size) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            if (ok[ok.size()-1] <= k) return;
            int B = ok.size()-1;
            for (int i = B-1; i >= 0; i--) {
                if (ok[i] <= k) {
                    B = i+1;
                    break;
                }
                B = i;
            }
            // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
            flag = 2;
            v.emplace_back(ok[B]); // small(1) flag
            DFS1_3(n+1);
        } else if (flag == 2) { // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
            v.emplace_back(ok[0]);
            DFS1_3(n+1);
        }
    }
}


// N_size-1
void DFS2(int n) {
    if (n == N_size-1) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            flag = 2;
            v.emplace_back(ok[ok.size()-1]);
            DFS2(n+1);
        } else if (flag == 2) { // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
            v.emplace_back(ok[ok.size()-1]);
            DFS2(n+1);
        }
    }
}

// N_size+1
void DFS3(int n) {
    if (n == N_size+1) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            flag = 1;
            if (n == 0 && ok[0] == 0 && ok.size() > 1) v.emplace_back(ok[1]);
            else v.emplace_back(ok[0]);
            DFS3(n+1);
        } else if (flag == 1) { // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
            v.emplace_back(ok[0]);
            DFS3(n+1);
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N_string >> M;
    N = std::stol(N_string);
    N_size = N_string.size();
    min = ABS(N-100);
    for (int i = 0; i < M; i++) {
        std::cin >> temp;
        no.emplace_back(temp);
    }
    for (int i = 0; i <= 9; i++) {
        if (std::find(no.begin(), no.end(), i) == no.end()) { // 쓸 수 있으면
            ok.emplace_back(i);
        }
    }
    if (N == 100) {
        std::cout << 0;
    } else {
        if (M < 10) {
            flag = 0;
            v.clear();
            DFS1(0);

            flag = 0;
            v.clear();
            DFS1_2(0);

            flag = 0;
            v.clear();
            DFS1_3(0);

            if (N_size > 1) {
                flag = 0;
                v.clear();
                DFS2(0);
            }

            flag = 0;
            v.clear();
            DFS3(0);
        }
        std::cout << min;
    }
    return 0;
}

/*

// 2023. 8. 17 11:43 -
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ABS(x)        ( ((x)<0)?-(x):(x) )

int N, M, N_size, min, flag, check, fake0;
std::string N_string;
std::vector<int> ok, no, v;

void DFS(int n) {
    if (n == N_size) {
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 && v[i] == 0 && fake0 == 1) {
                continue;
            }
            temp_string += std::to_string(v[i]);
            temp++;
        }
        if (temp_string == "") {
            temp_string = "0";
            temp = 1;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        int k = N_string[n]-48; 
        // v에 OK에서 N_string[n]과 가장 가까운 수 넣기(여러개면 차례대로 넣기)
        if (flag == 0) { // 같으면 같은 거 넣기
            if (std::find(ok.begin(), ok.end(), k) != ok.end()) {
                v.emplace_back(k);
                DFS(n+1);
            } else {
                if (ok[0] > k) { // 해당 값이 넣을 수 있는 모든 수보다 작은 경우
                    flag = 2;
                    v.emplace_back(ok[0]);
                    DFS(n+1);
                    for (int i = check; i >= n; i--) {
                        v.pop_back();
                    }
                    if (n == 0) {
                        flag = 1;
                        fake0 = 1;
                        v.emplace_back(0);
                        DFS(n+1);
                        for (int i = check; i >= n; i--) {
                            v.pop_back();
                        }
                    }
                } else if (ok[ok.size()-1] < k) { // 해당 값이 넣을 수 있는 모든 수보다 큰 경우
                    flag = 1;
                    v.emplace_back(ok[ok.size()-1]);
                    DFS(n+1);
                    for (int i = check; i >= n; i--) {
                        v.pop_back();
                    }
                    if (n == 0) {
                        flag = 2;
                        N_size++;
                        v.emplace_back(1);
                        DFS(n+1);
                        for (int i = check; i >= n; i--) {
                            v.pop_back();
                        }
                    }
                } else { // 큰 값 작은 값 모두 있는 경우
                    int A = 0;
                    int a = ABS(ok[A] - k);
                    for (int i = A+1; i < ok.size(); i++) {
                        if (ok[i] > k) {
                            A = i-1;
                            a = ABS(ok[i-1] - k);
                            break;
                        }
                    }
                    int B = ok.size()-1;
                    int b = ABS(ok[B] - k);
                    for (int i = B-1; i >= 0; i--) {
                        if (ok[i] < k) {
                            B = i+1;
                            b = ABS(ok[i+1] - k);
                            break;
                        }
                    }
                    if (a < b) {
                        // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
                        flag = 1;
                        v.emplace_back(ok[A]); // small(1) flag
                        DFS(n+1);
                    } else if (a > b) {
                        // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
                        flag = 2;
                        v.emplace_back(ok[B]); // big(2) flag
                        DFS(n+1);
                    } else if (a == b) {
                        flag = 1;
                        v.emplace_back(ok[A]);
                        DFS(n+1);
                        for (int i = check; i >= n; i--) {
                            v.pop_back();
                        }

                        flag = 2;
                        v.emplace_back(ok[B]);
                        DFS(n+1);
                        v.pop_back();
                    }
                }
            }
        } else if (flag == 1) { // 작은거면 그 다음부터는 넣을 수 있는 값 중 제일 큰 값만 넣기
            v.emplace_back(ok[ok.size()-1]);
            check = n;
            DFS(n+1);
        } else if (flag == 2) { // 큰거면 그 다음부터는 넣을 수 있는 값 중 제일 작은 값만 넣기
            v.emplace_back(ok[0]);
            check = n;
            DFS(n+1);
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N_string >> M;
    N = std::stol(N_string);
    N_size = N_string.size();
    min = ABS(N-100);
    for (int i = 0; i < M; i++) {
        std::cin >> temp;
        no.emplace_back(temp);
    }
    for (int i = 0; i <= 9; i++) {
        if (std::find(no.begin(), no.end(), i) == no.end()) { // 쓸 수 있으면
            ok.emplace_back(i);
        }
    }
    if (N == 100) {
        std::cout << 0;
    } else {
        if (M < 10) {
            DFS(0);
        }
        std::cout << min;
    }
    return 0;
}

*/