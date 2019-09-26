#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct rottery {
    string number;
    int money;
};

void solution(int test_case) {
    int N, M;
    long long answer = 0;

    cin >> N >> M;

    // rottery *0123456789

    vector<struct rottery> target;
    vector<string> numbers;

    for (int i = 0; i < N; i++) {
        struct rottery temp;
        cin >> temp.number >> temp.money;
        target.push_back(temp);
    }
    
    for (int index = 0; index < M; index++) {
        string now;
        cin >> now;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 8; j++) {
                if (target[i].number[j] != now[j] &&
                    target[i].number[j] != '*') {
                    break;
                }
                if (j == 7) {
                    answer += target[i].money;
                }
            }
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