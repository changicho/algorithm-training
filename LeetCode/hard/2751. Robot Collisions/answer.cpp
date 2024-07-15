#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use sort & stack
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Robot {
    int health;
    int position;
    char dir;
    int index;
  };

 public:
  vector<int> survivedRobotsHealths(vector<int> &positions,
                                    vector<int> &healths, string directions) {
    int size = positions.size();

    vector<Robot> robots;
    for (int i = 0; i < size; i++) {
      robots.push_back({healths[i], positions[i], directions[i], i});
    }

    sort(robots.begin(), robots.end(),
         [](Robot &a, Robot &b) { return a.position < b.position; });

    vector<Robot> remains;
    stack<Robot> lefts;
    for (int i = size - 1; i >= 0; i--) {
      if (robots[i].dir == 'L') {
        lefts.push(robots[i]);
      } else if (robots[i].dir == 'R') {
        bool isDestroyed = false;

        while (!lefts.empty()) {
          if (lefts.top().health > robots[i].health) {
            lefts.top().health--;
            isDestroyed = true;
            break;
          } else if (lefts.top().health == robots[i].health) {
            lefts.pop();
            isDestroyed = true;
            break;
          } else {
            robots[i].health--;
            lefts.pop();
          }
        }

        if (!isDestroyed) {
          remains.push_back(robots[i]);
        }
      }
    }

    while (!lefts.empty()) {
      remains.push_back(lefts.top());
      lefts.pop();
    }

    sort(remains.begin(), remains.end(),
         [](Robot &a, Robot &b) { return a.index < b.index; });

    vector<int> answer;
    for (Robot &remain : remains) {
      answer.push_back(remain.health);
    }
    return answer;
  }
};