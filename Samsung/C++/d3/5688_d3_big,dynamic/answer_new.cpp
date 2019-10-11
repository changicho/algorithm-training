#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    long long answer;
    long long N;
    cin >> N;

    answer = cbrt((double)N);

    if (pow(answer + 1, 3) == N) {
        answer += 1;
    }
    if (pow(answer, 3) != N) {
        answer = -1;
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