#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
    string numbers;
    cin >> numbers;

    int table[10] = {
        0,
    };

    for (char c : numbers) {
        table[c - '0']++;
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < table[i]; j++) {
            cout << i;
        }
    }
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}