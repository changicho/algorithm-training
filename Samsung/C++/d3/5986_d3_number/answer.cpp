#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool numbers[1000];

void solution(int test_case) {
    int N;
    cin >> N;

    int X, Y, Z;
    int answer = 0;

    int sum = 0;

    for (int i = 2; i <= N - 4;) {
        if (numbers[i]) {
            i += 2;
            continue;
        }
        sum += i;

        for (int j = i; j <= N - 4;) {
            if (numbers[j]) {
                j += 2;
                continue;
            }
            sum += j;

            if (sum > N) {
                sum -= j;
                break;
            }
            if (!numbers[N - i - j] && j <= N - i - j) {

                answer++;
            }

            sum -= j;
            if (j == 2) {
                j += 1;
            } else {
                j += 2;
            }
        }

        sum = 0;

        if (i == 2) {
            i += 1;
        } else {
            i += 2;
        }
    }

    cout << "#" << test_case << " " << answer;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    numbers[1] = true;
    // 에라토스테네스의 채를 이용해 소수를 구함.
    for (int i = 4; i < 1000; i += 2) {
        numbers[i] = true;
    }

    for (int i = 3; i <= 997; i += 2) {
        if (numbers[i]) {
            continue;
        }
        for (int j = i * 2; j < 1000; j += i) {
            numbers[j] = true;
        }
    }

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}