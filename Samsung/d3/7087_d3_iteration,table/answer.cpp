#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int N, answer = 0;
    vector<int> alphabet_count(26);
    
    cin >> N;

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;

        alphabet_count[temp[0] - 'A']++;
    }

    for (int i = 0; i < alphabet_count.size(); i++) {
        if (alphabet_count[i] == 0) {
            break;
        }
        answer++;
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