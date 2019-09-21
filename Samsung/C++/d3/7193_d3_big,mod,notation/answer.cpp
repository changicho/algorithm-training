#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, notation;
    int answer = 0;
    string number;

    cin >> N >> number;
    notation = N - 1;

    for (char c : number) {
        answer += (c - '0') % notation;
        if (answer > notation) {
            answer %= notation;
        }
    }

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