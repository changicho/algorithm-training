#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use find maximum

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int size = candies.size();
    int maximum = candies.front();

    for (int &candy : candies) {
      maximum = max(maximum, candy);
    }

    vector<bool> answer;
    for (int &candy : candies) {
      if (candy + extraCandies >= maximum) {
        answer.emplace_back(true);
      } else {
        answer.emplace_back(false);
      }
    }

    return answer;
  }
};

// use one pass with STL

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int size = candies.size();
    int maximum = *max_element(candies.begin(), candies.end());

    vector<bool> answer(size, false);
    for (int i = 0; i < size; i++) {
      if (candies[i] + extraCandies >= maximum) {
        answer[i] = true;
      }
    }

    return answer;
  }
};