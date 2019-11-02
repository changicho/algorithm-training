#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int N, M;

bool visited[8];
int combination[8];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << combination[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        combination[depth] = arr[i];

        visited[i] = true;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}