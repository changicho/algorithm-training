#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<bool> combination(N);

    for (int i = 0; i < M; i++) {
        combination[i] = true;
    }

    do {
        for (int i = 0; i < combination.size(); i++) {
            if (combination[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    } while (prev_permutation(combination.begin(), combination.end()));

    return 0;
}