#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, Q;
    cin >> N >> Q;

    int box[1001] = {
        0,
    };

    int L, R;
    for (int i = 1; i <= Q; i++) {
        cin >> L >> R;
        for (int j = L; j <= R; j++) {
            box[j] = i;
        }
    }

    cout << "#" << test_case << " ";
    for (int i = 1; i <= N; i++) {
        cout << box[i] << " ";
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