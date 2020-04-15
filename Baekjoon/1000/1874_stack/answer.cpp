#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, temp, index = 0;
  cin >> N;

  queue<char> answer;
  queue<int> arr;
  stack<int> s;

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    arr.push(temp);
  }

  for (int i = 1; i <= N; i++) {
    s.push(i);
    answer.push('+');

    while (!s.empty() && s.top() == arr.front()) {
      s.pop();
      answer.push('-');
      arr.pop();
    }
  }

  if (!s.empty()) {
    cout << "NO\n";
    return;
  }

  while (!answer.empty()) {
    cout << answer.front() << "\n";
    answer.pop();
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}