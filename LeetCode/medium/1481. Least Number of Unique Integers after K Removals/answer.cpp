#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use BST map
// time : O(N + K + M * log_2(M))
// space : O(M)
class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    map<int, unordered_set<int>> countByKey;

    unordered_map<int, int> counts;
    // O(N)
    for (int &num : arr) {
      counts[num]++;
    }
    // O(M * log_2(M))
    for (auto &it : counts) {
      countByKey[it.second].insert(it.first);
    }

    int deleteCount = 0;
    // O(K)
    while (deleteCount < k) {
      // O(1)
      auto it = countByKey.begin();
      int count = it->first;
      int target = *it->second.begin();

      if (deleteCount + count > k) break;

      it->second.erase(target);
      deleteCount += count;
      if (it->second.size() == 0) {
        // O(1)
        countByKey.erase(it);
      }
    }

    int answer = 0;
    // O(M)
    for (auto &it : countByKey) {
      answer += it.second.size();
    }
    return answer;
  }
};

// use heap
// time : O(N + (M + K) * log_2(M))
// space : O(M)
class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> counts;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // O(N)
    for (int &num : arr) {
      counts[num]++;
    }

    // O(M)
    for (auto &it : counts) {
      // O(log_2(M))
      minHeap.push(it.second);
    }

    int deleteCount = 0;
    // O(K)
    while (deleteCount < k) {
      if (minHeap.top() + deleteCount > k) break;

      deleteCount += minHeap.top();
      // O(log_2(M))
      minHeap.pop();
    }

    return minHeap.size();
  }
};