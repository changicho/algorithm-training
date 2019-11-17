#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int A, B, C;
    int count = 0;
    cin >> A >> B >> C;

    if (A > B) {
        count = C / B;
    } else {
        count = C / A;
    }

    cout << "#" << test_case << " " << count;
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