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

// use binary search
// time : O(M * log_2(N))
// space : O(N)
class Router {
 private:
  int limit = 0;
  unordered_map<int, vector<long long>> um;
  unordered_map<int, int> erased;

  queue<vector<int>> q;

  unordered_set<string> us;

  string convert(vector<int> nums) {
    string ret = to_string(nums[0]) + "/" + to_string(nums[1]) + "/" +
                 to_string(nums[2]);

    return ret;
  }

 public:
  Router(int memoryLimit) { limit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    string key = convert({source, destination, timestamp});

    if (us.count(key) > 0) return false;

    if (q.size() == limit) {
      forwardPacket();
    }

    us.insert(key);
    q.push({{source, destination, timestamp}});

    um[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (q.empty()) return {};

    vector<int> target = q.front();
    q.pop();

    us.erase(convert(target));

    erased[target[1]]++;

    return target;
  }

  int getCount(int destination, int startTime, int endTime) {
    return upper_bound(um[destination].begin() + erased[destination],
                       um[destination].end(), endTime) -
           lower_bound(um[destination].begin() + erased[destination],
                       um[destination].end(), startTime);
  }
};
