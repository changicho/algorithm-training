#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int N) {
    string str_number;
    string answer;

    for (int index = 1; index <= N; index++) {
        answer = "";
        str_number = to_string(index);
        for (int j = 0; j < str_number.length(); j++) {
            if (str_number[j] == '3' || str_number[j] == '6' ||
                str_number[j] == '9') {
                answer += '-';
            }
        }
        if (answer.length() == 0) {
            answer = str_number;
        }
        cout << answer << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    solution(N);

    return 0;
}