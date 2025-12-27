#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort
// time : O(E * (log_2(E) + N))
// space : O(E + N)
class Solution {
 private:
  vector<int> split(string& line) {
    stringstream ss(line);
    vector<int> ret;
    string temp;

    while (ss >> temp) {
      int id = stoi(temp.substr(2));
      ret.push_back(id);
    }
    return ret;
  }

 public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    sort(events.begin(), events.end(), [&](const auto& a, const auto& b) {
      int atimestamp = stoi(a[1]);
      int btimestamp = stoi(b[1]);
      if (atimestamp != btimestamp) {
        return atimestamp < btimestamp;
      }
      return a[0] > b[0];
    });

    vector<int> answer(numberOfUsers);
    vector<bool> isOnline(numberOfUsers, true);

    queue<pair<int, int>> q;

    for (vector<string>& e : events) {
      string type = e[0];
      int timestamp = stoi(e[1]);

      while (!q.empty() && q.front().first <= timestamp) {
        isOnline[q.front().second] = true;
        q.pop();
      }

      if (type == "MESSAGE") {
        if (e[2] == "ALL") {
          for (int i = 0; i < numberOfUsers; i++) {
            answer[i]++;
          }
        } else if (e[2] == "HERE") {
          for (int i = 0; i < numberOfUsers; i++) {
            if (isOnline[i]) answer[i]++;
          }
        } else {
          vector<int> targets = split(e[2]);

          for (int i : targets) {
            answer[i]++;
          }
        }
      } else {
        int target = stoi(e[2]);

        isOnline[target] = false;
        q.push({timestamp + 60, target});
      }
    }

    return answer;
  }
};