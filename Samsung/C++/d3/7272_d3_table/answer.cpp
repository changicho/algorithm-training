#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    char rules[] = {'1', '2', '0', '1', '0', '0', '0', '0', '0',
                    '0', '0', '0', '0', '0', '1', '1', '1', '1',
                    '0', '0', '0', '0', '0', '0', '0', '0'};

    string first, second, answer = "DIFF";

    cin >> first >> second;

    if (first.size() != second.size()) {
        cout << "#" << test_case << " " << answer << "\n";
        return;
    }

    for (int index = 0; index < first.size(); index++) {
        first[index] = rules[first[index] - 'A'];
        second[index] = rules[second[index] - 'A'];
    }

    if (first == second) {
        answer = "SAME";
    } else {
        answer = "DIFF";
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