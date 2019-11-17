#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> memory;

void solution(int test_case) {
    long long answer = 1;
    long long triple = 1;

    long long N;
    cin >> N;

    for (int i = 0; i < memory.size(); i++) {
        if (N >= memory[i]) {
            answer = (i + 1) * 100000;
            break;
        }
    }

    while (true) {
        triple = answer * answer * answer;

        if (N == triple) {
            break;
        }
        if (N < triple) {
            answer = -1;
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

    for (long long i = 100000; i <= 1000000; i += 100000) {
        long long temp = i * i * i;
        memory.push_back(temp);
    }

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}