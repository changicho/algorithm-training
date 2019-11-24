#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  bool answer = true;
  int length;
  string word;

  cin >> word;
  length = word.length();

  string first = word.substr(0, length / 2);
  string second = word.substr((length + 1) / 2, length);

  reverse(second.begin(), second.end());

  for (int index = 0; index < length / 2; index++) {
    if (first[index] == '?' || second[index] == '?') {
      continue;
    }
    if (first[index] != second[index]) {
      answer = false;
      break;
    }
  }

  cout << "#" << test_case << " ";
  if (answer) {
    cout << "Exist\n";
    return;
  }
  cout << "Not exist\n";
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