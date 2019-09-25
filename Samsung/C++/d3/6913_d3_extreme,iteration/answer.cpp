#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, M;
    int max = 0;
    vector<int> score;
    int temp;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp == 1) {
                count++;
            }
        }
        if (count > max) {
            max = count;
        }
        score.push_back(count);
    }

    int answer = 0;
    for (int s : score) {
        if (s == max) {
            answer++;
        }
    }

    cout << "#" << test_case << " " << answer << " " << max;
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