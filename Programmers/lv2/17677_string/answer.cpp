#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> first, second;
const int MULTI = 65536;

bool isFine(string str) {
  for (char c : str) {
    if (c < 'a' || c > 'z') {
      return false;
    }
  }
  return true;
}

map<string, int> parse(string str) {
  map<string, int> result;

  for (int i = 0; i < str.length() - 1; i++) {
    string temp = "";
    temp += tolower(str[i]);
    temp += tolower(str[i + 1]);

    if (isFine(temp)) {
      result[temp] += 1;
    }
  }

  return result;
}

int solution(string str1, string str2) {
  int answer = 0;
  int total = 0, same = 0;
  first = parse(str1);
  second = parse(str2);

  for (auto it = first.begin(); it != first.end(); it++) {
    total += it->second;
  }
  for (auto it = second.begin(); it != second.end(); it++) {
    total += it->second;
  }

  for (auto it = first.begin(); it != first.end(); it++) {
    for (int i = 0; i < it->second; i++) {
      if (second[it->first] > 0) {
        same += 1;
        second[it->first] -= 1;
      }
    }
  }

  total -= same;

  if (total == same) {
    return MULTI;
  }

  return same * MULTI / total;
}

struct TestCase {
  string str1;
  string str2;
  int answer;
};

int main() {
  vector<TestCase> testCases = {
      {"FRANCE", "french", 16384},
      {"handshake", "shake hands", 65536},
      {"aa1+aa2", "AAAA12", 43690},
      {"E=M*C^2", "e=m*c^2", 65536}};

  for (TestCase testCase : testCases) {
    int answer = solution(testCase.str1, testCase.str2);

    cout << "answer : " << answer << ", myAnswer " << testCase.answer << "\n";
  }

  return 0;
}