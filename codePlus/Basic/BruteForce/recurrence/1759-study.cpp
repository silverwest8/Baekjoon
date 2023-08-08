#include <iostream>
#include <vector>
#include <algorithm>

int L, C; // L : 사용한 알파벳 종류 수, C : 가능한 알파벳 종류 수
char before = 0; // 오름차순 출력을 위한 변수
char v[15 + 1];
char v2[15 + 1]; // 출력할 알파벳 배열
bool visited[15 + 1]; // dfs용

void dfs(int depth) {
    int vowel, consonant;
	if (depth == L) {
		vowel = consonant = 0;
		for (int i = 0; i < L; i++) {
			if (v2[i] == 'a' || v2[i] == 'e' || v2[i] == 'i' || v2[i] == 'o' || v2[i] == 'u') vowel++;
			else consonant++;
		}
		if (vowel < 1 || consonant < 2) return;
		else {
			for (int j = 0; j < L; j++) {
				printf("%c", v2[j]);
			}
			puts("");
			return;
		}

	}
	for (int i = 0; i < C; i++) {
		if (!visited[i] && v[i]>before) { // before : 오름차순을 위한 이전 알파벳과 비교
			visited[i] = true;
			v2[depth] = v[i];
			dfs(depth + 1);
			before = v[i];
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) 
		scanf(" %c", &v[i]);
	std::sort(v, v + C);
	dfs(0);
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#define max 15

int L, C;
std::vector<char> v;
std::vector<bool> visited(max+1, false);

void dfs(int start, int depth) {
	if (start == L) {
		int vowel = 0;
		for (int i = 0; i < v.size(); i++) {
			if (visited[i]) {
				if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
					vowel++;
			}
		}
		if (vowel >= 1 && L-vowel >= 2) {
			for (int i = 0; i < v.size(); i++)
				if (visited[i])
					std::cout << v[i];
			std::cout << "\n";
		}
	} else {
        for (int i = depth; i < v.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(start + 1, i);
                visited[i] = 0;
            }
        }
    }
}

int main() {
	std::cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char temp;
		std::cin >> temp;
		v.emplace_back(temp);
	}
	std::sort(v.begin(), v.end());
	dfs(0, 0);
	return 0;
}
*/