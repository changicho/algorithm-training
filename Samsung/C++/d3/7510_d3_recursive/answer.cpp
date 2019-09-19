#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    int answer = 0;
    int center;
    cin >> N;

    center = N / 2 + 1;

    if ((N - 1) % 2 == 0) {
        answer++;
    }
    for (int index = 1; index < center; index += 2) {
        if (N % index == 0) {
            cout << index << " ";
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