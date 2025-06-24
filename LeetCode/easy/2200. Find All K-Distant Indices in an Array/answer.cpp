#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass with hash set
// time : O(N * K)
// space : O(N)
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int size = nums.size();

    unordered_set<int> indexes;
    vector<int> answer;

    for (int i = 0; i < size; i++) {
      if (nums[i] != key) continue;

      for (int j = max(0, i - k); j < min(size, i + k + 1); j++) {
        indexes.insert(j);
      }
    }

    for (int idx : indexes) {
      answer.push_back(idx);
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// use two pointer
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int size = nums.size();
    vector<int> answer;
    for (int i = 0, j = 0; i < size; ++i) {
      if (nums[i] != key) continue;

      for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j) {
        answer.push_back(j);
      }
    }

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int size = nums.size();

    vector<int> answer;
    int minimum = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == key) {
        int left = max(minimum, i - k);
        int right = min(size - 1, i + k);

        for (int j = left; j <= right; j++) {
          answer.push_back(j);
        }

        minimum = right + 1;
      }
    }

    return answer;
  }
};

// use monotonic queue
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int size = nums.size();

    deque<int> dq;
    int lastIdx = -1;
    vector<int> answer;
    for (int i = 0; i < size; i++) {
      if (nums[i] == key) {
        lastIdx = i;
        while (!dq.empty()) {
          answer.push_back(dq.front());
          dq.pop_front();
        }
      }

      dq.push_back(i);
      if (dq.size() > k) {
        dq.pop_front();
      }

      if (lastIdx != -1 && !dq.empty() && dq.front() - lastIdx <= k) {
        answer.push_back(dq.front());
        dq.pop_front();
      }
    }
    return answer;
  }
};