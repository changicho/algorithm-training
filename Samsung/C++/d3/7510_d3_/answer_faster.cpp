#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    int answer = 0;
    cin >> N;

    for (int y = 0; y <= N; y++) {
        int numerator = 2 * N - y * y - y;
        int denominator = 2 * y + 2;

        if (numerator <= 0) {
            break;
        }

        if (numerator % denominator == 0) {
            answer++;
        }
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