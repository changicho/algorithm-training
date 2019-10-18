#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    string numbers;
    cin >> numbers;

    int answer = 0;
    int count = 0;

    count += numbers[0] - '0';
    for (int i = 1; i < numbers.size(); i++) {
        // 현재 박수를 치기에 사람이 모자라면
        if (i > count) {
            int extra = i - count;
            answer += extra;
            count += extra;
        }

        count += numbers[i] - '0';
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