#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(N)
vector<string> split(string &s) {
  vector<string> ret;
  stringstream ss(s);
  string temp;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

// change to 10digit
int change(int num, int digit) {
  int ret = 0;
  int cur = 1;

  while (num > 0) {
    ret += (num % 10) * cur;
    cur *= digit;
    num /= 10;
  }
  return ret;
}

int calc(string &a, string &operation, string &b, int digit) {
  for (char &c : a) {
    if (c >= (digit + '0')) return -1;
  }
  for (char &c : b) {
    if (c >= (digit + '0')) return -1;
  }

  int numA = change(stoi(a), digit), numB = change(stoi(b), digit);

  int sum = operation == "+" ? numA + numB : numA - numB;
  if (sum == 0) return 0;
  if (sum < 0) return -1;

  string ret = "";
  while (sum > 0) {
    ret += (sum % digit + '0');
    sum /= digit;
  }
  reverse(ret.begin(), ret.end());

  return stoi(ret);
}

bool isCorrect(string s, int digit) {
  vector<string> tokens = split(s);

  int result = calc(tokens[0], tokens[1], tokens[2], digit);

  if (result == -1) return false;

  if (tokens.back() == "X") return true;
  int target = stoi(tokens.back());
  return result == target;
}

string getResult(string &s, int digit) {
  vector<string> tokens = split(s);

  int result = calc(tokens[0], tokens[1], tokens[2], digit);

  return to_string(result);
}

vector<string> solution(vector<string> expressions) {
  vector<string> answer;

  vector<int> validDigits;
  for (int digit = 2; digit <= 9; digit++) {
    bool isFine = true;
    for (string &e : expressions) {
      if (!isCorrect(e, digit)) {
        isFine = false;
        break;
      }
    }

    if (!isFine) continue;
    validDigits.push_back(digit);
  }

  for (string &e : expressions) {
    if (e.back() != 'X') continue;

    unordered_set<string> results;
    for (int &digit : validDigits) {
      results.insert(getResult(e, digit));
    }

    if (results.size() >= 2) {
      e.pop_back();
      e.push_back('?');
    } else {
      e.pop_back();
      string result = *results.begin();
      e += result;
    }
    answer.push_back(e);
  }
  return answer;
}

// ===

struct TestCase {
  vector<string> expressions;
  vector<string> answer;
};

int main() {
  vector<TestCase> tcs = {
      // {{"14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"}, {"13 - 6 = 5"}},
      // {{"1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"},
      //  {"1 + 5 = ?", "1 + 2 = 3"}},
      // {{"10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X"},
      //  {"10 - 2 = 4", "3 + 3 = 10", "33 + 33 = 110"}},
      {{"2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X"},
       {"2 + 2 = 4", "7 + 4 = ?", "5 - 5 = 0"}},
      // {{"2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "8 + 4 = X"},
      //  {"2 + 2 = 4", "7 + 4 = 12", "8 + 4 = 13"}},
  };

  for (TestCase &tc : tcs) {
    vector<string> answer = solution(tc.expressions);

    for (string &s : answer) {
      cout << s << endl;
    }
  }

  return 0;
}