#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, M;

    cin >> N >> M;

    vector<int> arr(N + M + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[i + j]++;
        }
    }

    int max = 0;
    for (int index = 0; index < arr.size(); index++) {
        if (arr[index] > max) {
            max = arr[index];
        }
    }

    cout << "#" << test_case << " ";
    for (int index = 0; index < arr.size(); index++) {
        if (arr[index] == max) {
            cout << index << " ";
        }
    }
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