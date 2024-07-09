#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N * K)
// space : O(N)
class Solution {
 public:
  int findTheWinner(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }

    while (q.size() > 1) {
      for (int i = 0; i < k - 1; i++) {
        q.push(q.front());
        q.pop();
      }

      q.pop();
    }

    return q.front();
  }
};

// use math
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findTheWinner(int n, int k) {
    int answer = 0;
    for (int i = 2; i <= n; i++) {
      answer = (answer + k) % i;
    }
    return answer + 1;
  }
};