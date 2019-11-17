#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
    int N;
    cin >> N;

    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i : numbers) {
        cout << i << endl;
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