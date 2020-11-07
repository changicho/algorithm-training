#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  long long answer = 0;
  stack<long long> s;
  cin >> N;

  vector<long long> histograms(N);

  for (int i = 0; i < N; i++) {
    cin >> histograms[i];
  }

  for (int i = 0; i <= N; i++) {
    while (!s.empty() && histograms[s.top()] > histograms[i]) {
      long long top = s.top();
      s.pop();

      int width = s.empty() ? i : i - s.top() - 1;

      answer = max(answer, histograms[top] * width);
    }
    s.push(i);
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