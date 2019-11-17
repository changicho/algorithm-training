#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    unsigned int answer = 1;
    vector<char> diff;

    string str;
    cin >> str;

    if (str.length() == 1) {
        cout << "#" << test_case << " 1\n";
        return;
    }

    // 맨 첫글자와 마지막 글자는 직접 계산해주자.
    if (str[0] != str[1]) {
        answer *= 2;
    }

    for (int index = 1; index < str.length() - 1; index++) {
        diff.resize(0);

        // index - 1 , index , index + 1 번째 같은걸 제외한 개수를 구해야한다.
        for (int i = -1; i <= 1; i++) {
            diff.push_back(str[index + i]);
        }
        sort(diff.begin(), diff.end());
        diff.erase(unique(diff.begin(), diff.end()), diff.end());

        answer *= diff.size();
        answer %= 1000000007;
    }

    if (str[str.length() - 2] != str[str.length() - 1]) {
        answer *= 2;
    }

    answer %= 1000000007;

    cout << "#" << test_case << " ";
    cout << answer << "\n";

    vector<char>().swap(diff);
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}