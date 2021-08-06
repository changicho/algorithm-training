#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use convert diff

class Solution {
 private:
  string convert(vector<int> v) {
    string ret = "";
    for (int &num : v) {
      ret += to_string(num) + '/';
    }
    return ret;
  }

 public:
  vector<vector<string>> groupStrings(vector<string> &strings) {
    // use diffs of chars to key

    // step1. create hash map
    unordered_map<string, vector<string>> um;

    // step2. convert string to key and push it to hash map
    for (string &str : strings) {
      char center = str.front();
      vector<int> arr;

      // step3. get diff of all char from front charactor
      for (char &c : str) {
        arr.emplace_back((center - c + 26) % 26);
      }

      string key = convert(arr);
      um[key].emplace_back(str);
    }

    // step4. convert hash map to vector
    vector<vector<string>> answer;
    for (auto &cur : um) {
      answer.emplace_back(cur.second);
    }
    return answer;
  }
};