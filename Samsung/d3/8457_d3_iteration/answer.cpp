#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, B, E, input_number;
    int answer = 0;
    int multiple;

    cin >> N >> B >> E;

    for (int i = 0; i < N; i++) {
        cin >> input_number;
        multiple = input_number;
        while (multiple <= B + E) {
            if (multiple >= B - E) {
                answer++;
                break;
            }
            multiple += input_number;
        }
    }

    cout << "#" << test_case << " " << answer << "\n";
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