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

bool check(vector<int> &target, vector<vector<int>> &q, vector<int> &ans) {
  int size = q.size();

  unordered_set<int> us(target.begin(), target.end());

  for (int i = 0; i < size; i++) {
    vector<int> query = q[i];
    int a = ans[i];

    int count = 0;
    for (int &num : query) {
      if (us.count(num)) count++;
    }

    if (count != a) return false;
  }
  return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
  int answer = 0;

  vector<int> temp;

  function<void(void)> recursive = [&]() {
    if (temp.size() == 5) {
      if (check(temp, q, ans)) answer++;
      return;
    }

    int start = temp.empty() ? 1 : temp.back() + 1;

    for (int num = start; num <= n; num++) {
      temp.push_back(num);
      recursive();
      temp.pop_back();
    }
  };

  recursive();

  return answer;
}