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

// use one pass
// time : O(N * L)
// space : O(N)
class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    int size = words.size();
    vector<int> answer;

    for (int i = 0; i < size; i++) {
      if (words[i].find(x) != -1) {
        answer.push_back(i);
      }
    }
    return answer;
  }
};