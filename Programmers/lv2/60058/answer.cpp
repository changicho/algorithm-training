#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
// 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
//   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
// 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
//   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
//   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
//   4-3. ')'를 다시 붙입니다.
//   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
//   4-5. 생성된 문자열을 반환합니다.

vector<string> divide(string p) {
  int openCount = 0;
  string a = "", b = "";

  for (int i = 0; i < p.length(); i++) {
    a += p[i];
    if (p[i] == '(') {
      openCount += 1;
    } else {
      openCount -= 1;
    }

    if (openCount == 0) {
      for (int j = i + 1; j < p.length(); j++) {
        b += p[j];
      }
      break;
    }
  }

  return {a, b};
}

bool isFine(string p) {
  stack<char> s;

  for (char c : p) {
    if (c == '(') {
      s.push('(');
    } else {
      if (s.size() != 0 && s.top() == '(') {
        s.pop();
      } else {
        return false;
      }
    }
  }

  if (s.size() == 0) {
    return true;
  }
  return false;
}

string reverse(string p) {
  if (p.length() <= 2) {
    return "";
  }
  string newLine = "";

  for (int i = 1; i < p.length() - 1; i++) {
    if (p[i] == '(') {
      newLine += ')';
    } else {
      newLine += '(';
    }
  }
  return newLine;
}

string solution(string p) {
  if (p == "") return "";

  vector<string> uv = divide(p);
  string u = uv[0];
  string v = uv[1];

  if (isFine(u)) {
    return u + solution(v);
  } else {
    string newLine = "(";
    newLine += solution(v);
    newLine += ")";

    newLine += reverse(u);

    return newLine;
  }
}

struct testCase {
  string p;
  string result;
};

int main() {
  vector<testCase> testCases = {
      {"(()())()", "(()())()"}, {")(", "()"}, {"()))((()", "()(())()"}};

  for (testCase testCase : testCases) {
    string answer = solution(testCase.p);

    cout << "answer : " << answer << ", myAnswer " << testCase.result << "\n";
  }

  return 0;
}