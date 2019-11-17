#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int X1, Y1, X2, Y2, N;
    int case_inner = 0, case_line = 0, case_out = 0;

    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if ((X1 < x && x < X2) && (Y1 < y && y < Y2)) {
            case_inner++;
            continue;
        }

        if ((X1 == x || X2 == x) && (Y1 <= y && y <= Y2)) {
            case_line++;
            continue;
        }

        if ((X1 <= x && x <= X2) && (Y1 == y || Y2 == y)) {
            case_line++;
            continue;
        }

        case_out++;
    }

    cout << "#" << test_case << " " << case_inner << " " << case_line << " "
         << case_out;
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