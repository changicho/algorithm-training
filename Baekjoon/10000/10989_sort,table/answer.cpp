#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int table[10001];
void solution() {
    int N;
    cin >> N;

    int max = 0;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        table[temp]++;
        if (temp > max) {
            max = temp;
        }
    }

    for (int i = 0; i < max + 1; i++) {
        for (int j = 0; j < table[i]; j++) {
            cout << i << "\n";
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