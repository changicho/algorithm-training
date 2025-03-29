#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string convertToStr(long long target) {
  string ret = "";

  while (target > 0) {
    int add = target % 26;
    target /= 26;

    int cur = -1;

    cur += add;

    if (!ret.empty() && ret.back() == 'z') {
      cur--;
    }

    ret += (cur == -1 ? 'z' : (cur + 'a'));
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

long long convertToNum(string ban) {
  int size = ban.size();

  long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret *= 26;
    ret += (ban[i] - 'a') + 1;
  }

  return ret;
}

string solution(long long n, vector<string> bans) {
  sort(bans.begin(), bans.end(), [](string &a, string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
  });

  for (string &ban : bans) {
    if (convertToNum(ban) <= n) n++;
  }

  return convertToStr(n);
}