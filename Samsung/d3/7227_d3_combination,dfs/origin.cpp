#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long get_distance(vector<bool> combination, vector<pair<int, int>> worms) {
    long long distance_x = 0;
    long long distance_y = 0;

    for (int index = 0; index < worms.size(); index++) {
        if (combination[index]) {
            distance_x += worms[index].first;
            distance_y += worms[index].second;
        } else {
            distance_x -= worms[index].first;
            distance_y -= worms[index].second;
        }
    }

    long long distance = distance_x * distance_x + distance_y * distance_y;

    return distance;
}

void solution(int test_case) {
    vector<pair<int, int>> worms;
    int N;
    long long answer = -1;

    cin >> N;
    worms.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> worms[i].first >> worms[i].second;
    }

    // 이동O, 이동X 지렁이를 나누는 경우의 수를 구하기 위한 벡터 생성
    vector<bool> combination;
    for (int i = 0; i < N / 2; i++) {
        combination.push_back(false);
    }
    for (int i = 0; i < N / 2; i++) {
        combination.push_back(true);
    }

    do {
        long long distance = get_distance(combination, worms);
        if (answer == -1) {
            answer = distance;
        }
        if (answer > distance) {
            answer = distance;
        }

    } while (next_permutation(combination.begin(), combination.end()));

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