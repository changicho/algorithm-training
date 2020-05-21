#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

char table[36];

void init() {
  for (int i = 0; i < 10; i++) {
    table[i] = to_string(i)[0];
  }

  for (int i = 'A'; i <= 'Z'; i++) {
    table[i - 'A' + 10] = i;
  }
}

void solution() {
  long long N;
  int B;
  string answer = "";

  cin >> N >> B;

  stack<long long> s;

  s.push(N % B);
  N /= B;

  while (N != 0) {
    s.push(N % B);
    N /= B;
  }

  while (!s.empty()) {
    answer += table[s.top()];
    s.pop();
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  solution();

  return 0;
}