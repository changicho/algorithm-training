#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, int n) {
  vector<string> ret;
  int count = 0;
  string temp = "";

  for (char c : s) {
    temp += c;

    count += 1;

    if (count >= n) {
      ret.push_back(temp);
      temp = "";
      count = 0;
    }
  }

  if (temp != "") {
    ret.push_back(temp);
  }

  return ret;
}

int solution(string s) {
  int answer = s.length();

  for (int size = 1; size <= s.length() / 2; size++) {
    int cur_answer = 0;

    vector<string> parts = split(s, size);

    int count = 1;
    for (int i = 1; i < parts.size(); i++) {
      if (parts[i - 1] == parts[i]) {
        count += 1;
        continue;
      }

      if (count == 1) {
        cur_answer += parts[i - 1].length();
      } else {
        cur_answer += to_string(count).length() + parts[i - 1].length();
      }
      count = 1;
    }

    if (count == 1) {
      cur_answer += parts.back().length();
    } else {
      cur_answer += to_string(count).length() + parts.back().length();
    }

    answer = min(answer, cur_answer);
  }

  return answer;
}

struct test_case {
  string s;
  int answer;
};

int main() {
  vector<test_case> t_s = {
      {"aabbaccc", 7},           {"ababcdcdababcdcd", 9},
      {"abcabcdede", 8},         {"abcabcabcabcdededededede", 14},
      {"xababcdcdababcdcd", 17}, {"abrabcabcadqabcabc", 14}};

  for (test_case t : t_s) {
    int a = solution(t.s);

    cout << a << " " << t.answer << "\n";
  }

  // for (int i = 2; i < 3; i++) {
  //   test_case t = t_s[i];

  //   int a = solution(t.s);

  //   cout << a << " " << t.answer << "\n";
  // }

  return 0;
}