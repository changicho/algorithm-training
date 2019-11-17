#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long arr[1001];

long long facto(int n) {
    long long answer = 1;
    for (int i = 1; i <= n; i++) {
        answer *= i;
        answer %= 1000000007;
    }
    return answer;
}

void solution(int test_case) {
    int N;
    cin >> N;

    cout << "#" << test_case << " " << arr[N];
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    arr[2] = 1;
    for (int i = 3; i <= 1000; i++) {
        arr[i] = (i * arr[i - 1] + (i / 2) * facto(i - 1)) % 1000000007;
    }

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}