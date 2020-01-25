#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> cards;
int answer;

void dfs(int index, int count, int sum) {
    if (count == 3) {
        if (sum <= M) {
            answer = max(sum, answer);
        }
        return;
    }

    if (index == N) {
        return;
    }

    dfs(index + 1, count + 1, sum + cards[index]);
    dfs(index + 1, count, sum);
}

void solution() {
    cin >> N >> M;
    answer = 0;
    cards.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    dfs(0, 0, 0);

    cout << answer << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}