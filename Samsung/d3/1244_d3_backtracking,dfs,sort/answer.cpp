#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int C, answer;

void dfs(int count, int index, string number) {
  if (count == C) {
    answer = max(stoi(number), answer);
    return;
  }

  for (int i = index; i < number.length(); i++) {
    for (int j = i + 1; j < number.length(); j++) {
      if (number[i] <= number[j]) {
        string new_number = number;
        swap(new_number[i], new_number[j]);

        dfs(count + 1, i, new_number);
      }
    }
  }
}

void clear() { answer = 0; }

void solution(int test_case) {
  clear();
  string number;

  cin >> number >> C;

  dfs(0, 0, number);

  cout << "#" << test_case << " " << answer << "\n";
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