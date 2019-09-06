#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/** 
 * 문자열을 입력받아 문자열의 패턴 길이를 return해주는 함수
 * argumant : void
 * return : int
 * O(N) : 최대 10^3
*/
int solution() {
    string input;
    string pattern = "";
    int pattern_number = 1;
    int start_point;
    cin >> input;

    for (int index = 0; index < 10; index++) {
        pattern += input[index];

        while (true) {
            start_point = (pattern.length()) * pattern_number;
            if (input.find(pattern, start_point) == start_point) {
                pattern_number++;
            } else {
                break;
            }
        }
        if (pattern_number > 1) {
            return pattern.length();
        }
        pattern_number = 1;
    }

    return 0;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "#" << i + 1 << " " << solution() << endl;
    }

    return 0;
}