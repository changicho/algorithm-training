#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    int after[999];
    int before[999];
    int answer = 0;

    cin >> N;

    // 요소 입력
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        before[i] = temp % 3;
        after[i] = (i + 1) % 3;
    }

    for (int i = 0; i < N - 1; i++) {
        // 바꿀 필요가 없을 때
        if (after[i] == before[i]) {
            continue;
        }

        // 바꿀 곳을 찾음
        for (int j = i + 1; j < N; j++) {
            // 완벽한 경우
            if ((after[i] == before[j]) && (after[j] == before[i])) {
                int temp = before[i];
                before[i] = before[j];
                before[j] = temp;
                answer++;

                break;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (after[i] == before[i]) {
            continue;
        }
        count++;
    }
    answer += (count / 3) * 2;

    cout << "#" << test_case << " " << answer;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}