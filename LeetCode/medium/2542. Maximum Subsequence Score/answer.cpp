#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int size = nums1.size();

    // min, add
    vector<pair<int, int>> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({nums2[i], nums1[i]});
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    priority_queue<int, vector<int>, greater<int>> pq;

    long long answer = 0;
    long long cur = 0;
    for (int i = 0; i < k - 1; i++) {
      cur += arr[i].second;
      pq.push(arr[i].second);
    }

    for (int i = k - 1; i < size; i++) {
      cur += arr[i].second;
      pq.push(arr[i].second);
      answer = max(answer, cur * arr[i].first);

      cur -= pq.top();
      pq.pop();
    }

    return answer;
  }
};