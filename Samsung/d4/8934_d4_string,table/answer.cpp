#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalin(string word) {
  int length = word.length();

  string first = word.substr(0, length / 2);
  string second = word.substr((length + 1) / 2, length);

  reverse(second.begin(), second.end());

  for (int index = 0; index < length / 2; index++) {
    if (first[index] == '?' || second[index] == '?') {
      continue;
    }
    if (first[index] != second[index]) {
      return false;
      break;
    }
  }
  return true;
}

void solution(int test_case) {
  string answer = "YES";
  string str;
  vector<int> count;
  count.resize(3, 0);

  cin >> str;

  for (char c : str) {
    count[c - 'a']++;
  }

  sort(count.begin(), count.end());

  count[2] -= count[0];

  if (count[2] > 1) {
    answer = "NO";
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