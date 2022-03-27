#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use GCD & stack
// time : O(N * log_2(M))
// space : O(N)
class Solution {
 private:
  // O(log_2(A + B))
  long long LCM(long long a, long long b) { return a * b / gcd(a, b); }

  // O(log_2(A + B))
  bool isCoPrime(int &a, int &b) { return gcd(a, b) == 1; }

 public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    int size = nums.size();
    // O(N)
    vector<int> answer;

    // O(N)
    for (int &num : nums) {
      // trim answer if can make LCM back with current
      // total O(N)
      while (!answer.empty() && !isCoPrime(answer.back(), num)) {
        // O(log_2(M))
        num = LCM(num, answer.back());
        answer.pop_back();
      }
      answer.push_back(num);
    }

    return answer;
  };
}