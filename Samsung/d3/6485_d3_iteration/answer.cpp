#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct line {
    int start;
    int end;
};

void solution(int test_case) {
    int N, P;
    cin >> N;
    vector<struct line> lines;
    for (int i = 0; i < N; i++) {
        struct line temp;
        cin >> temp.start >> temp.end;
        lines.push_back(temp);
    }

    cin >> P;

    cout << "#" << test_case << " ";

    for (int i = 0; i < P; i++) {
        int station;
        cin >> station;
        int answer = 0;
        for (struct line l : lines) {
            if (l.start <= station && station <= l.end) {
                answer++;
            }
        }
        cout << answer << " ";
    }

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