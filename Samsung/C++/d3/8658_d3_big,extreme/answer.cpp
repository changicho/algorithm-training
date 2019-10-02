#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    string numbers[10];

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    int min, max;

    int answer = 0;
    for (char c : numbers[0]) {
        answer += c - '0';
    }
    max = min = answer;

    for (string n : numbers) {
        answer = 0;
        for (char c : n) {
            answer += c - '0';
        }

        if (min > answer) {
            min = answer;
        }
        if (max < answer) {
            max = answer;
        }
    }

    cout << "#" << test_case << " " << max << " " << min;
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