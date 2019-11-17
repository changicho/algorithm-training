#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int D, A, B, F;
    cin >> D >> A >> B >> F;

    double time = (double)D / (double)(A + B);

    // cout << time << endl;

    double distance = time * (double)F;

    cout << "#" << test_case << " " << distance;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(7);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}