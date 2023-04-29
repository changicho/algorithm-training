#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

// circular
// R : 0, P : 1, S : 2
int getMinDist(vector<int> &nums) {
  int size = nums.size();
  int dp[1001][3] = {
      0,
  };
  memset(dp, -1, sizeof(dp));

  dp[0][nums[0]] = 0;

  for (int i = 1; i < size; i++) {
    // cur type, minimum cost
    for (int type = 0; type <= 2; type++) {
      int minimum = INT_MAX;

      for (int before = 0; before <= 2; before++) {
        if (before == type) continue;
        if (dp[i - 1][before] < 0) continue;

        int curCost = dp[i - 1][before] + (nums[i] != type ? 1 : 0);

        minimum = min(minimum, curCost);
      }

      if (minimum != INT_MAX) dp[i][type] = minimum;
    }
  }

  return dp[size - 1][nums[size - 1]];
}

int solution(string &line) {
  int size = line.size();
  vector<int> nums(size);
  for (int i = 0; i < size; i++) {
    if (line[i] == 'R') {
      nums[i] = 0;
    } else if (line[i] == 'P') {
      nums[i] = 1;
    } else {
      nums[i] = 2;
    }
  }

  int answer = INT_MAX;
  for (int front = 0; front <= 2; front++) {
    for (int back = 0; back <= 2; back++) {
      if (front == back) continue;

      int beforeFront = nums[0], beforeBack = nums[size - 1];
      int diffCost = 0;
      if (nums[0] != front) {
        diffCost++;
        nums[0] = front;
      }
      if (nums[size - 1] != back) {
        diffCost++;
        nums[size - 1] = back;
      }
      int curCost = getMinDist(nums) + diffCost;
      answer = min(answer, curCost);

      nums[0] = beforeFront;
      nums[size - 1] = beforeBack;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    string line;
    cin >> line;

    int answer = solution(line);

    // cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << endl;
    cout << "Case #" << testCase << ": " << answer << endl;
  }

  return 0;
}