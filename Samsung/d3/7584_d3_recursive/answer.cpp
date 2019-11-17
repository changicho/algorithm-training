#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string f(string input) {
    for (int index = 0; index < input.size(); index++) {
        if (input[index] == '0') {
            input[index] = '1';
        } else {
            input[index] = '0';
        }
    }
    return input;
}

string g(string input) {
    reverse(input.begin(), input.end());
    return input;
}

void solution(int test_case) {
    long long n;
    bool answer = 0;
    cin >> n;
    n--;

    while (n > 0) {
        if (n % 2 == 1) {
            n = (n - 1) / 2;
        }

        if (n % 4 == 0) {
            answer = 0;
            break;
        } 
        
        if (n % 2 == 0) {
            answer = 1;
            break;
        }
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