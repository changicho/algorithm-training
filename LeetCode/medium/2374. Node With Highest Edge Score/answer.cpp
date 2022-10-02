#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int edgeScore(vector<int>& edges) {
    int size = edges.size();

    vector<long long> scores(size, 0);

    for (int i = 0; i < size; i++) {
      scores[edges[i]] += i;
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (scores[answer] < scores[i]) {
        answer = i;
      }
    }

    return answer;
  }
};