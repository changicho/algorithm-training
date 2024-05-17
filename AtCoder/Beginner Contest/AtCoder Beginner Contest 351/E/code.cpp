#include <algorithm>
#include <cmath>
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

struct Axis {
  long long y, x;
};

long long getDist(vector<long long> &nums) {
  int MOVE_DIST = 2;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  long long sum = accumulate(nums.begin(), nums.end(), 0LL);

  long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret += (sum - nums[i] * (size - i));
    sum -= nums[i];
  }
  return ret / MOVE_DIST;
}

long long solution(int size, vector<Axis> &positions) {
  vector<long long> firstY, firstX, secondY, secondX;

  for (Axis &p : positions) {
    // rotate 45 degree
    // use euler's formula
    // y' = x sin(45) + y cos(45)
    // x' = x cos(45) - y sin(45)
    // cos(45) = sin(45) = 1 / sqrt(2)
    // so use euler's formula and multiply sqrt(2)
    // p = (x + y, x - y)
    Axis converted = {p.x + p.y, p.x - p.y};

    if ((p.y + p.x) % 2 == 0) {
      firstY.push_back(converted.y);
      firstX.push_back(converted.x);
    } else {
      secondY.push_back(converted.y);
      secondX.push_back(converted.x);
    }
  }

  long long answer = 0;
  answer += getDist(firstY);
  answer += getDist(firstX);
  answer += getDist(secondY);
  answer += getDist(secondX);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Axis> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].y >> P[i].x;
  }

  long long answer = solution(N, P);
  cout << answer << "\n";

  return 0;
}