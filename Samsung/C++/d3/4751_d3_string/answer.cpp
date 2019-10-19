#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printEnd(int length) {
    for (int i = 0; i < length; i++) {
        cout << "..#.";
    }
    cout << ".\n";
}

void printSecond(int length) {
    for (int i = 0; i < length; i++) {
        cout << ".#.#";
    }
    cout << ".\n";
}

void solution(int test_case) {
    string s;

    cin >> s;
    int length = s.length() * 3 + 2;

    printEnd(s.length());
    printSecond(s.length());

    for (int i = 0; i < s.length(); i++) {
        cout << "#." << s[i] << ".";
    }
    cout << "#\n";

    printSecond(s.length());
    printEnd(s.length());
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