#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    string number;
    int answer = 0;
    cin >> number;

    switch (number.length()) {
        case 3:
            answer = 1;
            break;
        case 4:
            answer = 2;
            break;
        case 5:
            answer = 3;
            break;
        case 6:
            answer = 4;
            break;
    }

    if (number.length() > 6) {
        answer = 5;
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