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
 private:
  struct Project {
    int capital;
    int profit;
  };

 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    int size = profits.size();

    vector<Project> projects;  // capital, profits
    for (int i = 0; i < size; i++) {
      projects.push_back({capital[i], profits[i]});
    }
    sort(projects.begin(), projects.end(),
         [](Project& a, Project& b) { return a.capital < b.capital; });

    priority_queue<int> pq;
    int i = 0;
    while (k--) {
      while (i < size && projects[i].capital <= w) {
        pq.push(projects[i].profit);
        i++;
      }

      if (pq.empty()) break;

      w += pq.top();
      pq.pop();
    }
    return w;
  }
};