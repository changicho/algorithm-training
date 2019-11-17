#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, R;
    long long divition = 1234567891;
    long long answer;

    cin >> N >> R;

    vector<long long> factorial(N + 1);

    factorial[0] = 1;
    factorial[1] = 1;

    for (int index = 2; index <= N; index++) {
        factorial[index] = (factorial[index - 1] * index) % divition;
    }

    // n! / (n-r)! * r!
    answer = factorial[N] / (factorial[N - R] * factorial[R]);
    answer %= divition;

    cout << "#" << test_case << " " << answer << "\n";
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