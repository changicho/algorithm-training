#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    cin >> N;

    long sum = 0;
    long max = 0;
    int current_num;

    for (int i = 0; i < N; i++) {
        cin >> current_num;
        sum += current_num;
        if (sum > max) {
            max = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "#" << test_case << " " << max << "\n";
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