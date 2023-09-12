#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    unordered_map<int, vector<int>> um;

    int size = groupSizes.size();

    for (int i = 0; i < size; i++) {
      um[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> answer;
    for (pair<int, vector<int>> cur : um) {
      int key = cur.first;
      vector<int> val = cur.second;

      if (key == val.size()) {
        answer.push_back(val);
      } else {
        vector<int> temp;
        for (int &num : val) {
          temp.push_back(num);

          if (temp.size() == key) {
            answer.push_back(temp);
            temp.resize(0);
          }
        }
      }
    }
    return answer;
  }
};