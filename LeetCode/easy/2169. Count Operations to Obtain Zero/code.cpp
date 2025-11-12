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

// use simulation
// time : O(max(N, M))
// space : O(1)
class Solution {
 public:
  int countOperations(int num1, int num2) {
    int answer = 0;
    while (num1 > 0 && num2 > 0) {
      answer++;

      if (num1 >= num2) {
        num1 -= num2;
      } else {
        num2 -= num1;
      }
    }
    return answer;
  }
};

// use euclidean
// time : O(log_2(max(N, M)))
// space : O(1)
class Solution {
 public:
  int countOperations(int num1, int num2) {
    int answer = 0;
    while (num1 && num2) {
      answer += num1 / num2;
      num1 %= num2;
      swap(num1, num2);
    }
    return answer;
  }
};