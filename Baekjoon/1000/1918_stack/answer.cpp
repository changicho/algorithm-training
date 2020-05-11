#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string line;
  string answer = "";
  stack<char> s;
  map<char, int> icp;  // stack 외부 우선순위
  map<char, int> isp;  // stack 내부 우선순위

  icp['+'] = isp['+'] = icp['-'] = isp['-'] = 1;
  icp['*'] = isp['*'] = icp['/'] = isp['/'] = 2;
  icp['('] = 3;
  isp['('] = 0;

  cin >> line;

  for (char c : line) {
    if ('A' <= c && c <= 'Z') {
      answer += c;
      continue;
    }

    switch (c) {
      case ')': {
        while (!s.empty() && s.top() != '(') {
          answer += s.top();
          s.pop();
        }
        // 남아있는 '(' 를 비워줌
        s.pop();
      } break;
      default: {
        // 현재 들어갈 연산자가 stack의 top보다 우선순위가 높을 때까지 반복
        while (!s.empty() && isp[s.top()] >= icp[c]) {
          if (s.top() != '(') {
            answer += s.top();
          }
          s.pop();
        }
        s.push(c);
      }
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