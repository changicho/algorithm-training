#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use sort & binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  int findLowerMaximum(map<int, int>& m, int target) {
    auto it = m.upper_bound(target);

    if (it == m.begin()) return -1;
    return prev(it)->first;
  }

 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int size = people.size();
    sort(people.begin(), people.end());

    map<int, int> counts;
    for (int& p : people) {
      counts[p]++;
    }

    int answer = 0;
    for (int i = size - 1; i >= 0; i--) {
      int cur = people[i];

      if (counts.count(cur) == 0) continue;

      counts[cur]--;
      if (counts[cur] == 0) counts.erase(cur);

      answer++;

      int target = findLowerMaximum(counts, limit - cur);

      if (target != -1 && counts[target] != 0) {
        counts[target]--;
        if (counts[target] == 0) counts.erase(target);
      }
    }
    return answer;
  }
};

// use sort & two pointer
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int size = people.size();
    sort(people.begin(), people.end());

    vector<int> lefts(size, 0);
    for (int i = 0; i < size; i++) {
      lefts[i] = limit - people[i];
    }

    int answer = size;
    for (int i = size - 1, j = 0; i > j; i--) {
      int person = people[i];

      if (person <= lefts[j]) {
        j++;
        answer--;
      }
    }
    return answer;
  }
};

// use sort & two pointer (space optimized)
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    int size = people.size();
    sort(people.begin(), people.end());

    int answer = size;
    int left = 0, right = size - 1;
    while (left < right) {
      int person = people[right];

      if (person <= limit - people[left]) {
        left++;
        answer--;
      }
      right--;
    }
    return answer;
  }
};