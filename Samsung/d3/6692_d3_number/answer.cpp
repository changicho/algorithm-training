#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N;
    cin >> N;
    double answer = 0;

    for (int i = 0; i < N; i++) {
        double P;
        int X;
        cin >> P >> X;
        answer += P * X;
    }
    
    cout << fixed;
    cout.precision(6);
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