#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// get crush count to make all distance lower than minimum dist
int getCrush(vector<int> &diffs, int minDist) {
  int crush = 0;

  int curDist = 0;
  for (int &diff : diffs) {
    curDist += diff;

    if (curDist < minDist) {
      // can ignore current rock so crush it
      crush++;
    } else {
      curDist = 0;
    }
  }

  return crush;
}

int solution(int distance, vector<int> rocks, int n) {
  int answer = distance;

  rocks.push_back(0);
  rocks.push_back(distance);
  sort(rocks.begin(), rocks.end());

  vector<int> diffs;
  for (int i = 0; i < rocks.size() - 1; i++) {
    diffs.push_back(rocks[i + 1] - rocks[i]);
  }

  int left = 0, right = distance + 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (getCrush(diffs, mid) <= n) {
      answer = mid;

      // move right
      left = mid + 1;
    } else {
      // move left
      right = mid;
    }
  }

  return answer;
}

// define main

struct TestCase {
  int distance;
  vector<int> rocks;
  int n;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {25, {2, 14, 11, 21, 17}, 2, 4},
      {25, {5, 10, 15, 20}, 4, 25},
      {25, {5, 10, 15, 20}, 1, 5},
  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.distance, tc.rocks, tc.n);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}