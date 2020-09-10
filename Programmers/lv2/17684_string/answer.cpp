#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  map<string, int> m;

  for (char alpha = 'A'; alpha <= 'Z'; alpha++) {
    string temp = "";
    m[temp + alpha] = m.size() + 1;
  }

  int index = 0;
  while (index < msg.length()) {
    string cur = "";
    int end;

    for (end = index; end < msg.length(); end++) {
      cur += msg[end];

      if (m[cur] == 0) {
        m[cur] = m.size();
        cur.erase(cur.length() - 1, 1);
        break;
      }
    }

    answer.push_back(m[cur]);
    index = end;
  }

  return answer;
}

struct TestCase {
  string msg;
  vector<int> answer;
};

string toString(vector<int> v) {
  string ret = "(";
  for (int i : v) {
    ret += to_string(i);
    ret += ", ";
  }
  ret.erase(ret.length() - 2, 2);
  ret += ")";
  return ret;
}

int main() {
  vector<TestCase> tcs = {
      {"KAKAO", {11, 1, 27, 15}},
      {"TOBEORNOTTOBEORTOBEORNOT", {20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34}},
      {"ABABABABABABABAB", {1, 2, 27, 29, 28, 31, 30}}};

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.msg);

    cout << "answer : " << toString(tc.answer) << ", myAnswer : " << toString(answer) << "\n";
  }

  return 0;
}