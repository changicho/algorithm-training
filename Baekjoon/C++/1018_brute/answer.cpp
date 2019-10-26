#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool board[50][50];
int count_diff(int start_y, int start_x) {
    bool flag;

    int first_count = 0;
    int second_count = 0;
    bool current_color;

    for (int i = start_y; i < start_y + 8; i++) {
        // 매 줄의 첫번째 색을 정함
        if (i % 2 == 0) {
            flag = true;
        } else {
            flag = false;
        }

        for (int j = start_x; j < start_x + 8; j++) {
            // 가능한 두가지 정답을 만들어놓음
            if (board[i][j] != flag) {
                first_count++;
            }
            if (board[i][j] == flag) {
                second_count++;
            }
            flag = !flag;
        }
    }

    return min(first_count, second_count);
}

void solution() {
    int N, M;
    int answer = 50 * 50;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < M; j++) {
            if (line[j] == 'W') {
                board[i][j] = false;
            } else {
                board[i][j] = true;
            }
        }
    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            answer = min(answer, count_diff(i, j));
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