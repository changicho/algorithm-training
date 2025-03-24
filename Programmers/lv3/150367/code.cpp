#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool check(string &bits) {
  int size = bits.size();
  bool isFine = true;
  int left = 0, right = size - 1;

  auto recursive = [&](int left, int right, char parent, auto &&recursive) {
    if (left > right) return;
    int mid = left + (right - left) / 2;

    char cur = bits[mid];

    if (parent == '0' && cur == '1') {
      isFine = false;
      return;
    }

    if (left == right) return;

    recursive(left, mid - 1, cur, recursive);
    recursive(mid + 1, right, cur, recursive);
  };

  recursive(0, right, '1', recursive);
  return isFine;
}

string convert(long long num) {
  string ret = "";
  while (num > 0) {
    ret += (num % 2) + '0';
    num /= 2;
  }

  int length = 1;
  while (ret.size() > (length - 1)) {
    length *= 2;
  }
  length--;
  ret += string(length - ret.size(), '0');

  reverse(ret.begin(), ret.end());

  return ret;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;

  for (long long &num : numbers) {
    string converted = convert(num);
    bool cur = check(converted);

    answer.push_back(cur);
  }

  return answer;
}