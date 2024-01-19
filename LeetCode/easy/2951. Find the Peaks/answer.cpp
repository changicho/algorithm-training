#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findPeaks(vector<int>& mountain) {
    int size = mountain.size();

    vector<int> answer;
    for (int i = 1; i < size - 1; i++) {
      if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
        answer.push_back(i);
      }
    }
    return answer;
  }
};