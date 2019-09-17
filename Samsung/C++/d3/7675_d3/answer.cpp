#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
    cout << "#" << test_case << " ";
    string word;
    int line;
    cin >> line;

    int line_count = 0;

    int count = 0;

    while (line != line_count) {
        bool is_word = false;
        bool is_started = false;

        cin >> word;

        if (word[0] >= 'A' && word[0] <= 'Z') {
            is_word = true;
        }

        for (int index = 1; index < word.size(); index++) {
            char current = word[index];

            if (current == '.' || current == '!' || current == '?') {
                if (is_word) {
                    count++;
                    is_word = false;
                }

                line_count++;
                cout << count << " ";
                count = 0;
                break;
            }

            if (is_word) {
                if (current < 'a' || current > 'z') {
                    // cout<<current<<" flase"<<endl;
                    is_word = false;
                }
            }
        }

        if (is_word) {
            count++;
        }
    }

    cout<<"\n";
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