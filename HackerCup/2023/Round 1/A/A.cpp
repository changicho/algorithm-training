#include <algorithm>
#include <cmath>
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

double mean(vector<int> nums) {
  double sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  return sum / nums.size();
}

double getCost(vector<int> nums) {
  double meanVal = mean(nums);
  double cost = 0;
  for (int i = 0; i < nums.size(); i++) {
    cost += abs(nums[i] - meanVal);
  }
  return cost;
}

double solution(vector<int> &positions) {
  sort(positions.begin(), positions.end());
  int size = positions.size();
  // do something

  if (size == 5) {
    double leftTwoCost = getCost({positions[2], positions[3], positions[4]}) +
                         getCost({positions[0], positions[1]});
    double leftThreeCost = getCost({positions[3], positions[4]}) +
                           getCost({positions[0], positions[1], positions[2]});

    double leftTwo =
        mean({positions[2], positions[4]}) - mean({positions[0], positions[1]});
    double leftThree =
        mean({positions[3], positions[4]}) - mean({positions[0], positions[2]});

    if (leftTwoCost < leftThreeCost) {
      return leftTwo;
    }
    if (leftTwoCost > leftThreeCost) {
      return leftThree;
    }
    return min(leftTwo, leftThree);
  }

  return mean({positions[size - 2], positions[size - 1]}) -
         mean({positions[0], positions[1]});
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);
  freopen("./here_comes_santa_claus_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
      cin >> X[i];
    }

    double answer = solution(X);

    // cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << "\n";
    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}