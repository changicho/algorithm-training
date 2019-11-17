#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N = 5;
    string strs[N];
    string current_word;
    int max = 0;

    for (int i = 0; i < N; i++) {
        cin >> strs[i];
        if (strs[i].length() > max) {
            max = strs[i].length();
        }
    }

    cout << "#" << test_case << " ";

    current_word = "";

    for (int index = 0; index < max; index++) {
        for (int i = 0; i < N; i++) {
            if (strs[i].length() <= index) {
                continue;
            }
            current_word += strs[i][index];
        }
    }
    cout << current_word;
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