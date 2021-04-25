#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> constructList(vector<vector<int>> Q, int N) {
    // code here
    int XOR = 0;
    vector<int> ret = {
        0,
    };

    for (vector<int> query : Q) {
      if (query[0] == 0) {
        ret.push_back(query[1] ^ XOR);
      } else {
        XOR ^= query[1];
      }
    }

    for (int i = 0; i < ret.size(); i++) {
      ret[i] ^= XOR;
    }

    sort(ret.begin(), ret.end());

    return ret;
  }
};