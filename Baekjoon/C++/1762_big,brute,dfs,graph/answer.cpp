#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 100010

using namespace std;

long long answer = 0;
int N;
long long M;

vector<int> map[MAX];

void solution() {
    answer = 0;
    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        x--;
        y--;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {  // i : 시작점
        for (int j : map[i]) {     // j 는 2번째 점
            if (j < i) {
                continue;
            }
            for (int k : map[j]) {  // k 는 3번째 점
                if (k < j) {
                    continue;
                }
                if (find(map[k].begin(), map[k].end(), i) != map[k].end()) {
                    answer++;
                }
            }
        }
    }

    cout << answer << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}