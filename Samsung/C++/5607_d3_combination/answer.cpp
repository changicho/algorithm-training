#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, R;
    long long divition = 1234567891;
    long long index;
    long long squared;
    long long denominator;

    cin >> N >> R;

    vector<long long> factorial(N + 1);

    factorial[0] = 1;
    factorial[1] = 1;

    for (int index = 2; index <= N; index++) {
        factorial[index] = (factorial[index - 1] * index) % divition;
    }
    denominator = (factorial[R] * factorial[N - R]) % divition;

    index = divition - 2;
    squared = 1;

    // 분모 denominator 의 R-2 제곱 구하기
    while (index > 0) {
        if (index % 2 == 1) {
            squared *= denominator;
            squared %= divition;
        }
        denominator = (denominator * denominator) % divition;
        index /= 2;
    }

    long long result =
        ((factorial[N] % divition) * (squared % divition)) % divition;

    cout << "#" << test_case << " " << result << "\n";
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}