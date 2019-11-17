#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    int up_max = 0, down_max = 0;
    cin >> N;

    int now, before;
    cin >> before;
    for (int i = 1; i < N; i++) {
        cin >> now;

        // 지금 더 높은곳
        if (now > before) {
            if (up_max < now - before) {
                up_max = now - before;
            }
        }
        if (now < before) {
            if (down_max < before - now) {
                down_max = before - now;
            }
        }

        before = now;
    }

    cout << "#" << test_case << " " << up_max << " " << down_max;
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