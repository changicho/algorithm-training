#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, K;
    cin >> N >> K;

    bool students[100] = {
        false,
    };

    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        students[temp - 1] = true;
    }

    cout << "#" << test_case << " ";

    for (int i = 0; i < N; i++) {
        if (!students[i]) {
            cout << i + 1 << " ";
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