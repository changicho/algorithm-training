#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution(int N) {
  long long answer = 0;
  stack<long long> s;
  vector<long long> histograms(N + 1, 0);

  for (int i = 0; i < N; i++) {
    cin >> histograms[i];
  }

  for (int index = 0; index <= N; index++) {
    while (!s.empty() && histograms[s.top()] >= histograms[index]) {
      long long top = s.top();
      s.pop();

      long long width = s.empty() ? index : (index - s.top() - 1);
      answer = max(answer, histograms[top] * width);
    }
    s.push(index);
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  while (true) {
    cin >> N;
    if (N == 0) {
      return 0;
    }
    solution(N);
  }

  return 0;
}