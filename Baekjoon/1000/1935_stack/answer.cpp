#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

double table['Z' - 'A' + 1];

void solution() {
  int N;
  string line;

  cin >> N;
  cin >> line;

  for (int i = 0; i < N; i++) {
    cin >> table[i];
  }

  stack<double> num;

  for (char c : line) {
    if ('A' <= c && c <= 'Z') {
      num.push(table[c - 'A']);
      continue;
    }

    double first, second;
    first = num.top();
    num.pop();
    second = num.top();
    num.pop();
    switch (c) {
      case '+': {
        num.push(first + second);
        break;
      }
      case '-': {
        num.push(second - first);
        break;
      }
      case '*': {
        num.push(first * second);
        break;
      }
      case '/': {
        num.push(second / first);
        break;
      }
    }
  }

  cout << num.top() << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(2);

  solution();

  return 0;
}