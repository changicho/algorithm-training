#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use prime (sieve of eratosthenes) & DFS & prefix count
// time : O(N * sqrt(M))
// space : O(N)
class Solution {
 private:
  vector<int> primes = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                        37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                        83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                        139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                        197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                        263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
  vector<vector<int>> graph;

  unordered_map<int, long long> count;

  int getRemainPrime(int num) {
    int ret = 1;

    for (int& p : primes) {
      if (p > num) break;

      int count = 0;
      while (num % p == 0) {
        num /= p;
        count++;
      }

      if (count % 2 == 1) {
        ret *= p;
      }
    }

    return ret * num;
  }

  long long recursive(int node, int parent, vector<int>& nums) {
    int primes = getRemainPrime(nums[node]);

    long long ret = count[primes];

    count[primes]++;
    for (int& next : graph[node]) {
      if (next == parent) continue;

      ret += recursive(next, node, nums);
    }
    count[primes]--;
    return ret;
  }

 public:
  long long sumOfAncestors(int n, vector<vector<int>>& edges,
                           vector<int>& nums) {
    graph.resize(n);

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    long long answer = recursive(0, -1, nums);

    return answer;
  }
};

// use prime (sieve of eratosthenes) & DFS & prefix count
// time : O(N * sqrt(M) + M)
// space : O(N + sqrt(M))
class Solution {
 private:
  vector<int> primes;
  vector<vector<int>> graph;

  unordered_map<int, long long> count;

  int getRemainPrime(int num) {
    int ret = 1;

    for (int& p : primes) {
      if (p > num) break;

      int count = 0;
      while (num % p == 0) {
        num /= p;
        count++;
      }

      if (count % 2 == 1) {
        ret *= p;
      }
    }

    return ret * num;
  }

  // sieve of eratosthenes
  void init() {
    bool isNotPrime[1001] = {
        false,
    };

    int limit = sqrt(1e5);

    for (int i = 3; i <= limit; i += 2) {
      if (isNotPrime[i]) continue;

      for (int j = i + i; j <= limit; j += i) {
        isNotPrime[j] = true;
      }
    }

    primes.push_back(2);
    for (int i = 3; i <= limit; i += 2) {
      if (!isNotPrime[i]) primes.push_back(i);
    }
  }

  long long recursive(int node, int parent, vector<int>& nums) {
    int primes = getRemainPrime(nums[node]);

    long long ret = count[primes];

    count[primes]++;
    for (int& next : graph[node]) {
      if (next == parent) continue;

      ret += recursive(next, node, nums);
    }
    count[primes]--;
    return ret;
  }

 public:
  long long sumOfAncestors(int n, vector<vector<int>>& edges,
                           vector<int>& nums) {
    init();

    graph.resize(n);

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    long long answer = recursive(0, -1, nums);

    return answer;
  }
};