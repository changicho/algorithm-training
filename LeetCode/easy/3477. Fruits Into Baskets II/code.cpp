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

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int size = fruits.size();

    int answer = size;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (fruits[i] <= baskets[j]) {
          answer--;
          baskets[j] = 0;
          break;
        }
      }
    }

    return answer;
  }
};