#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int size = rating.size();

    vector<int> lowers(size, 0), uppers(size, 0);

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (rating[j] < rating[i]) {
          lowers[i]++;
        }
        if (rating[j] > rating[i]) {
          uppers[i]++;
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (rating[j] < rating[i]) {
          answer += lowers[j];
        }
        if (rating[j] > rating[i]) {
          answer += uppers[j];
        }
      }
    }
    return answer;
  }
};