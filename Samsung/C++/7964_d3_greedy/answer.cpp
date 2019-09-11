#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, D;
    cin >> N >> D;

    vector<int> arr(N + 2);
    // set gate at start, end
    arr[0] = 1;
    arr[N + 1] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int current_index = 0;
    int answer = 0;
    bool jump = false;

    while (current_index != N + 1) {
        jump = false;

        for (int i = current_index + 1; i <= current_index + D; i++) {
            if (arr[i] == 1) {
                current_index = i;
                jump = true;
                break;
            }
        }

        if (!jump) {
            current_index += D;
            arr[current_index] = 1;
            answer++;
        }
    }

    cout << "#" << test_case;
    cout << " " << answer << "\n";

    vector<int>().swap(arr);
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}