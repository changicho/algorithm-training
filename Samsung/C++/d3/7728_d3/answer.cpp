#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int answer = 0;
    string number;
    cin >> number;
    vector<bool> check(10);

    for (char c : number) {
        check[c - '0'] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (check[i]) {
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