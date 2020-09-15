#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

char tables[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string convert(int number, int digit) {
  string ret = "";

  while (number >= digit) {
    ret += tables[number % digit];
    number /= digit;
  }
  ret += tables[number];

  reverse(ret.begin(), ret.end());
  return ret;
}

string solution(int n, int t, int m, int p) {
  string answer = "";
  string line = "";
  vector<char> numbers;
  queue<bool> orders;

  for (int i = 1; i <= m; i++) {
    if (i == p) {
      orders.push(true);
    } else {
      orders.push(false);
    }
  }

  int index = 0;
  while (line.length() < t * m) {
    line += convert(index, n);
    index += 1;
  }

  int num = 0;
  while (numbers.size() < t) {
    if (orders.front()) {
      numbers.push_back(line[num]);
    }
    num += 1;
    orders.push(orders.front());
    orders.pop();
  }

  for (char num : numbers) {
    answer += num;
  }

  return answer;
}

struct TestCase {
  int n;
  int t;
  int m;
  int p;
  string result;
};

int main() {
  vector<TestCase> tcs = {
      {2, 4, 2, 1, "0111"},
      {16, 16, 2, 1, "02468ACE11111111"},
      {16, 16, 2, 2, "13579BDF01234567"}

  };

  for (TestCase tc : tcs) {
    string result = solution(tc.n, tc.t, tc.m, tc.p);

    bool isCorrect = result == tc.result;

    cout << isCorrect << ", answer : " << tc.result << ", myAnswer : " << result << "\n";
  }

  return 0;
}