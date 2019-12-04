#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  long long answer = 0;
  int N, temp;
  stack<int> numbers;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    if (temp == 0 && !numbers.empty()) {
      numbers.pop();
    } else {
      numbers.push(temp);
    }
  }

  while (!numbers.empty()) {
    answer += numbers.top();
    numbers.pop();
  }

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