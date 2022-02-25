#include <algorithm>
#include <cfloat>  // for DBL_MAX
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use greedy with heap
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Worker {
    int quality, wage;
    double ratio;

    bool operator<(const Worker& b) const { return ratio < b.ratio; }
  };

 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int size = quality.size();
    // O(N)
    vector<Worker> workers;

    for (int i = 0; i < size; i++) {
      workers.push_back(
          {quality[i], wage[i], (double)wage[i] / (double)quality[i]});
    }
    // O(N * log_2(N))
    sort(workers.begin(), workers.end());

    double answer = DBL_MAX;
    int sumQuality = 0;

    priority_queue<int> maxHeap;
    for (Worker& w : workers) {
      maxHeap.push(w.quality);
      sumQuality += w.quality;

      if (maxHeap.size() > k) {
        sumQuality -= maxHeap.top();
        maxHeap.pop();
      }

      if (maxHeap.size() == k) {
        answer = min(answer, sumQuality * w.ratio);
      }
    }

    return answer;
  }
};