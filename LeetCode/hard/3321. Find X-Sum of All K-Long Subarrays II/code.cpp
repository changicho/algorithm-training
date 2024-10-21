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

// use set
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct DataSet {
   private:
    unordered_map<int, int> counts;
    set<pair<int, int>> chosen, rest;

    long long sum = 0;
    int limit;
    int size = 0;

    void innerUpdate(int num) {
      if (chosen.empty() && rest.empty()) return;

      if (!counts.count(num)) return;

      pair<int, int> p = {counts[num], num};

      if (chosen.count(p)) {
        sum -= 1LL * num * counts[num];
        chosen.erase(p);
      } else if (rest.count(p)) {
        rest.erase(p);
      }
    }

   public:
    void add(int num) {
      size++;

      innerUpdate(num);
      counts[num]++;

      chosen.insert({counts[num], num});
      sum += 1LL * num * counts[num];

      if (chosen.size() > limit) {
        auto it = chosen.begin();
        rest.insert(*it);
        sum -= 1LL * it->first * it->second;
        chosen.erase(*it);
      }
    }

    void remove(int num) {
      size--;

      innerUpdate(num);

      counts[num]--;
      if (counts[num] == 0) {
        counts.erase(num);
      } else {
        rest.insert({counts[num], num});
      }

      while (chosen.size() < limit && !rest.empty()) {
        auto it = rest.rbegin();
        sum += 1LL * it->first * it->second;
        chosen.insert(*it);
        rest.erase(*it);
      }
    }

    long long getSum() { return sum; }
    int getSize() { return size; }

    DataSet(int limit) { this->limit = limit; }
  };

 public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int size = nums.size();

    DataSet ds(x);

    vector<long long> answer;

    for (int i = 0; i < size; i++) {
      ds.add(nums[i]);

      if (i >= k) {
        ds.remove(nums[i - k]);
      }

      if (ds.getSize() == k) {
        long long cur = ds.getSum();
        answer.push_back(cur);
      }
    }

    return answer;
  }
};