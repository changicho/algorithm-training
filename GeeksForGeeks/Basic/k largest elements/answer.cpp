#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 public:
  vector<int> kLargest(int arr[], int n, int k) {
    sort(arr, arr + n, greater<int>());
    vector<int> ret;
    for (int i = 0; i < k; i++) {
      ret.push_back(arr[i]);
    }

    return ret;
  }
};

// use priority queue

class Solution {
 public:
  vector<int> kLargest(int arr[], int n, int k) {
    vector<int> res;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
      pq.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
      if (pq.top() < arr[i]) {
        pq.pop();
        pq.push(arr[i]);
      }
    }

    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }

    reverse(res.begin(), res.end());

    return res;
  }
};