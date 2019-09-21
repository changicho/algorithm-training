#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long answer;
int worms [21][2];
bool visited [21];
int N;

long long get_distance() {
    long long distance_x = 0;
    long long distance_y = 0;

    for (int index = 0; index < N; index++) {
        if (visited[index]) {
            distance_x += worms[index][0];
            distance_y += worms[index][1];
        } else {
            distance_x -= worms[index][0];
            distance_y -= worms[index][1];
        }
    }

    long long distance = distance_x * distance_x + distance_y * distance_y;

    return distance;
}

void dfs(int index, int count) {
    // 끝에 도달
    if (count == N / 2) {
        long long distance = get_distance();
        if (answer == -1) {
            answer = distance;
        }
        if (answer > distance) {
            answer = distance;
        }
        return;
    }

    for (int i = index; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        dfs(i + 1, count + 1);
        visited[i] = false;
    }
}

void solution(int test_case) {
    answer = -1;

    cin >> N;
    for(int i=0;i<N;i++){
        visited[i] = false;
        worms[i][0] = 0;
        worms[i][1] = 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> worms[i][0] >> worms[i][1];
    }

    dfs(0, 0);

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