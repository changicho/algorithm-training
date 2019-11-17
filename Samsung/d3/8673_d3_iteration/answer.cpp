#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    // K는 20까지, 사람의 최대 수는 1024
    int K;
    long long answer = 0;
    cin >> K;
    int size = pow(2, K);

    vector<int> scores(size);

    for (int i = 0; i < size; i++) {
        cin >> scores[i];
    }

    for (int i = 0; i < K; i++) {
        vector<int> new_scores;
        for (int i = 0; i < scores.size(); i += 2) {
            if (scores[i] > scores[i + 1]) {
                answer += scores[i] - scores[i + 1];
                new_scores.push_back(scores[i]);
            } else {
                answer += scores[i + 1] - scores[i];
                new_scores.push_back(scores[i + 1]);
            }
        }
        scores = new_scores;
    }

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