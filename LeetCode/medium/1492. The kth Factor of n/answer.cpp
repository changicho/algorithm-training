#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use division and sort
// time : O(sqrt(N) + M * log_2(M))
// space : O(M)
class Solution {
 public:
  int kthFactor(int n, int k) {
    vector<int> factors;

    int sqrtN = sqrt(n);
    for (int num = 1; num <= sqrtN; num++) {
      if (n % num != 0) continue;

      factors.push_back(num);
      if (num != n / num) factors.push_back(n / num);
    }

    sort(factors.begin(), factors.end());
    if (k - 1 >= factors.size()) return -1;
    return factors[k - 1];
  }
};

// use sqrt with heap
// time : O(sqrt(N) * log_2(K))
// space : O(K)
class Solution {
 public:
  int kthFactor(int n, int k) {
    priority_queue<int> factors;

    int sqrtN = sqrt(n);
    for (int num = 1; num <= sqrtN; num++) {
      if (n % num != 0) continue;

      factors.push(num);
      if (num != n / num) factors.push(n / num);

      while (factors.size() > k) {
        factors.pop();
      }
    }

    if (k != factors.size()) return -1;
    return factors.top();
  }
};

// use math
// time : O(sqrt(N))
// space : O(min(K, sqrt(N)))
class Solution {
 public:
  int kthFactor(int n, int k) {
    vector<int> smalls;

    int sqrtN = sqrt(n);
    // we can first ~ k'th factor
    for (int num = 1; num <= sqrtN; num++) {
      if (n % num != 0) continue;

      k--;
      smalls.push_back(num);
      if (k == 0) return num;
    }

    // if n is perfect square
    if (sqrtN * sqrtN == n) {
      k++;
    }

    int smallSize = smalls.size();

    if (k <= smallSize) {
      return n / smalls[smallSize - k];
    }
    return -1;
  }
};