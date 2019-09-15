#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    int time_now[3], time_target[3], time_answer[3];
    string temp;

    cin >> temp;
    time_now[0] = std::stoi(temp.substr(0, 2));
    time_now[1] = std::stoi(temp.substr(3, 5));
    time_now[2] = std::stoi(temp.substr(6, 8));
    cin >> temp;

    time_target[0] = std::stoi(temp.substr(0, 2));
    time_target[1] = std::stoi(temp.substr(3, 5));
    time_target[2] = std::stoi(temp.substr(6, 8));

    time_answer[0] = time_target[0] - time_now[0];
    time_answer[1] = time_target[1] - time_now[1];
    time_answer[2] = time_target[2] - time_now[2];

    if (time_answer[2] < 0) {
        time_answer[1] -= 1;
        time_answer[2] += 60;
    }
    if (time_answer[1] < 0) {
        time_answer[0] -= 1;
        time_answer[1] += 60;
    }
    if (time_answer[0] < 0) {
        time_answer[0] += 24;
    }

    cout << "#" << test_case << " ";

    cout.fill('0');
    cout.width(2);

    cout << time_answer[0] << ":";

    cout.fill('0');
    cout.width(2);

    cout << time_answer[1] << ":";

    cout.fill('0');
    cout.width(2);

    cout << time_answer[2] << "\n";
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}