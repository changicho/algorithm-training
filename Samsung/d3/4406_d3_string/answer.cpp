#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string vowel = "aeiou";

void solution(int test_case) {
  string answer = "";
  string word;

  cin >> word;

  for (char c : word) {
    bool isVowel = false;
    for (char v : vowel) {
      if (c == v) {
        isVowel = true;
        break;
      }
    }

    if (isVowel) {
      continue;
    }
    answer += c;
  }

  cout << "#" << test_case << " ";
  cout << answer << "\n";
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