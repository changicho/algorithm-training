#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<string> arr;
    for (int i = 1; i <= n; i++) {
      arr.push_back(to_string(i));
    }

    sort(arr.begin(), arr.end());
    vector<int> ret;
    for (string &num : arr) {
      ret.push_back(stoi(num));
    }
    return ret;
  }
};