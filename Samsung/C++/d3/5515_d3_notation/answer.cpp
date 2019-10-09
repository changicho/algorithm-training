#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int calender[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int M, D;

    cin >> M >> D;

    int day = 3;
    for (int i = 0; i < M - 1; i++) {
        day += calender[i];
    }
    day += D;
    day %= 7;

    cout << "#" << test_case << " " << day;
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