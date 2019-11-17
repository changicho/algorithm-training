#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int x1, y1, x2, y2;
    int diff_x, diff_y;
    long long answer = -1;
    cin >> x1 >> y1 >> x2 >> y2;

    diff_x = abs(x1 - x2);
    diff_y = abs(y1 - y2);

    if (diff_x == 0 && diff_y == 0) {
        answer = 0;
    }

    while (abs(diff_x - diff_y) >= 2 && answer != 0) {
        if (diff_x > diff_y) {
            diff_y += 2;
        } else {
            diff_x += 2;
        }
    }

    if (abs(diff_x - diff_y) < 2) {
        answer = diff_x + diff_y;
    }

    cout << "#" << test_case << " " << answer;
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