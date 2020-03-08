#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void solution() {
  stack<int> s;

  long long answer = 0;
  int K, num;

  cin >> K;

  for (int i = 0; i < K; i++) {
    cin >> num;

    if (num == 0) {
      s.pop();
    } else {
      s.push(num);
    }
  }

  while (!s.empty()) {
    answer += s.top();
    s.pop();
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}