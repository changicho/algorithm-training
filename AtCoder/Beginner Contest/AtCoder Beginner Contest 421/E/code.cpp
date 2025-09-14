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

double solution(vector<int> &arr) {
  vector<map<vector<int>, double>> memo(4);

  function<double(int, vector<int>)> recursive = [&](int chance,
                                                     vector<int> keep) {
    if (chance == 0) {
      double res = 0;

      for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int x : keep) {
          if (x == arr[i]) count++;
        }

        res = max(res, (double)count * arr[i]);
      }

      return res;
    }

    chance--;

    if (memo[chance].count(keep)) {
      return memo[chance][keep];
    }

    function<double(int, vector<int>)> go = [&](int num, vector<int> dice) {
      if (num == 0) {
        int diceSize = dice.size();
        double res = 0;
        for (int s = 0; s < (1 << diceSize); s++) {
          vector<int> newKeep = keep;

          for (int i = 0; i < diceSize; i++) {
            if ((s >> i) & 1) newKeep.push_back(dice[i]);
          }

          res = max(res, recursive(chance, newKeep));
        }

        return res;
      }

      double res = 0;
      dice.push_back(0);
      for (int i = 0; i < 6; i++) {
        dice.back() = arr[i];
        res += go(num - 1, dice);
      }

      return res / 6.0;
    };

    double res = go(5 - keep.size(), {});
    return memo[chance][keep] = res;
  };

  double ans = recursive(3, {});

  return ans;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<int> A(6);
  for (int i = 0; i < 6; i++) {
    cin >> A[i];
  }

  auto answer = solution(A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}