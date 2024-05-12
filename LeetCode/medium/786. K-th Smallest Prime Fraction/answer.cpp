#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue
// time : O(N^2 * log_2(K))
// space : O(K)
class Solution {
 private:
  struct Prime {
    double val;
    int a, b;

    bool operator<(const Prime& b) const { return val < b.val; }
  };

 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int size = arr.size();
    priority_queue<Prime> pq;

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int a = arr[i], b = arr[j];
        pq.push({double(a) / b, a, b});
        if (pq.size() > k) pq.pop();
      }
    }

    Prime target = pq.top();
    return {target.a, target.b};
  }
};

// use priority queue & math
// time : O((N + K) * log_2(K))
// space : O(K)
class Solution {
 private:
  struct Prime {
    double val;
    int a, b;

    bool operator<(const Prime& b) const { return val > b.val; }
  };

 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int size = arr.size();
    priority_queue<Prime> pq;

    for (int i = 0; i < size; i++) {
      int a = i, b = size - 1;
      pq.push({double(arr[a]) / arr[b], a, b});
    }

    // iterate k-1
    while (k-- > 1) {
      Prime cur = pq.top();
      pq.pop();

      int a = cur.a, b = cur.b - 1;

      pq.push({double(arr[a]) / arr[b], a, b});
    }

    Prime target = pq.top();
    return {arr[target.a], arr[target.b]};
  }
};