#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> scores;
vector<int> calories;
int N, L, max_score;

void dfs(int start, int score, int calorie) {
    if (start == N) {
        if (calorie <= L && score > max_score) {
            max_score = score;
        }
        return;
    }

    dfs(start + 1, score, calorie);
    dfs(start + 1, score + scores[start], calorie + calories[start]);
}

void solution(int test_case) {
    cin >> N >> L;
    max_score = 0;

    scores.resize(N);
    calories.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> scores[i] >> calories[i];
    }

    dfs(0, 0, 0);

    cout << "#" << test_case << " " << max_score;
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