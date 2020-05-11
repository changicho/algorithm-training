#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string change(string original) {
  string ret = "";

  stack<char> s;
  map<char, int> icp;  // stack 외부 우선순위
  map<char, int> isp;  // stack 내부 우선순위

  icp['+'] = isp['+'] = 1;
  icp['-'] = isp['-'] = 1;
  icp['*'] = isp['*'] = 2;
  icp['/'] = isp['/'] = 2;
  icp['('] = 3;
  isp['('] = 0;

  for (char c : original) {
    if ('0' <= c && c <= '9') {
      ret += c;
      continue;
    }

    switch (c) {
      case ')': {
        while (!s.empty() && s.top() != '(') {
          ret += s.top();
          s.pop();
        }
        s.pop();
      } break;
      default: {
        while (!s.empty() && isp[s.top()] >= icp[c]) {
          if (s.top() != '(') {
            ret += s.top();
          }
          s.pop();
        }
        s.push(c);
      }
    }
  }

  while (!s.empty()) {
    ret += s.top();
    s.pop();
  }

  return ret;
}

long long calcul(string line) {
  long long ret = 0;

  stack<long long> nums;

  for (char c : line) {
    if ('0' <= c && c <= '9') {
      nums.push(c - '0');
    } else {
      long long second = nums.top();
      nums.pop();
      long long first = nums.top();
      nums.pop();

      switch (c) {
        case '+': {
          nums.push(first + second);
        } break;
        case '*': {
          nums.push(first * second);
        }
      }
    }
  }

  ret = nums.top();
  return ret;
}

void solution(int test_case) {
  long long answer;
  string line;

  cin >> line >> line;

  answer = calcul(change(line));

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}