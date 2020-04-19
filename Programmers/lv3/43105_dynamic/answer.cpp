#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[502][502];

int solution(vector<vector<int>> triangle) {
  int answer = 0;

  int level = 0;

  dp[0][0] = triangle[0][0];

  for (int i = 1; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      if (j - 1 >= 0) {
        dp[i][j] = max(dp[i - 1][j] + triangle[i][j],
                       dp[i - 1][j - 1] + triangle[i][j]);
      } else {
        dp[i][j] = dp[i - 1][j] + triangle[i][j];
      }
      answer = max(answer, dp[i][j]);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> triangle = {
      {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

  cout << solution(triangle) << "\n";
  return 0;
}