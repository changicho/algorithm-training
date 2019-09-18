#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define S_MAX 365
#define E_MAX 24
#define M_MAX 29

using namespace std;

void solution(int test_case) {
    int S, E, M;
    int S_temp = 0, E_temp = 0, M_temp = 0;
    long long answer;

    cin >> S >> E >> M;

    answer = S;

    while (true) {
        E_temp = (answer - 1) % E_MAX + 1;
        M_temp = (answer - 1) % M_MAX + 1;

        if (E == E_temp && M == M_temp) {
            break;
        }
        answer += S_MAX;
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