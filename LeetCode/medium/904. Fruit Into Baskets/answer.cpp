#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int size = fruits.size();

    unordered_map<int, int> baskets;
    int left = 0;
    int answer = 0;
    for (int right = 0; right < size; right++) {
      baskets[fruits[right]]++;

      while (baskets.size() > 2 && left < right) {
        baskets[fruits[left]]--;

        if (baskets[fruits[left]] == 0) {
          baskets.erase(fruits[left]);
        }
        left++;
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};
