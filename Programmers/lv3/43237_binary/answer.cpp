#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[100001];

int solution(vector<int> budgets, int M) {
  int answer;

  sort(budgets.begin(), budgets.end());

  for (int i = 1; i <= budgets.size(); i++) {
    dp[i] = dp[i - 1] + budgets[i - 1];
  }

  answer = min(answer, budgets.back());

  int min = 0;
  int max = budgets.back() + 1;

  while (min + 1 < max) {
    int mid = (min + max) / 2;

    int lower_count =
        lower_bound(budgets.begin(), budgets.end(), mid) - budgets.begin();
    int over_count = budgets.size() - lower_count;

    long long sum = dp[lower_count] + mid * over_count;

    if (sum <= M) {
      min = mid;
    } else {
      max = mid;
    }
  }

  answer = min;

  return answer;
}