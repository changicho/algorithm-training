#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    string target, sentence;
    int T;
    cin >> T >> target >> sentence;

    int answer = 0;
    int find_index = 0;

    do {
        find_index = sentence.find(target, find_index);
        if (find_index != -1) {
            answer++;
            find_index += target.length();
        }
    } while (find_index != -1 || find_index < sentence.length());

    cout << "#" << T << " " << answer;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}