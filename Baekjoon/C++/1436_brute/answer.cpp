#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_triple_six(long long number) {
    string number_string = to_string(number);

    if (number_string.find("666") != string::npos) {
        return true;
    }
    return false;
}

void solution() {
    long long answer = 665;
    int N;
    cin >> N;

    while (N != 0) {
        answer++;
        if (check_triple_six(answer)) {
            N--;
        }
    }

    cout << answer << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}