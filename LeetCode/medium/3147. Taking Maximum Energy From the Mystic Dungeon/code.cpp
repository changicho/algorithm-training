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

// use dynamic programming (in-place)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maximumEnergy(vector<int>& energy, int k) {
    int size = energy.size();

    int answer = INT_MIN;
    for (int i = 0; i < size; i++) {
      if (i - k >= 0) {
        int before = energy[i - k];

        energy[i] = max(energy[i], before + energy[i]);
      }

      if (i + k >= size) {
        answer = max(answer, energy[i]);
      }
    }
    return answer;
  }
};