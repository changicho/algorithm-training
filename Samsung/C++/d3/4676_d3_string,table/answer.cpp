#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int H;
    string str;
    cin >> str;
    cin >> H;
    vector<int> number(str.length());
    int before_size = 0;
    for (int i = 0; i < H; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            before_size++;
            continue;
        }
        number[temp - 1]++;
    }

    cout << "#" << test_case << " ";

    for (int i = 0; i < before_size; i++) {
        cout << "-";
    }
    for (int index = 0; index < str.length(); index++) {
        cout << str[index];
        for (int i = 0; i < number[index]; i++) {
            cout << "-";
        }
    }

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