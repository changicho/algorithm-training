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

// use stack
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Data {
    char c;
    int count;
  };

 public:
  string compressedString(string word) {
    vector<Data> stk;

    for (char &c : word) {
      if (stk.empty() || stk.back().c != c || stk.back().count == 9) {
        stk.push_back({c, 1});
        continue;
      }

      int count = stk.back().count;
      stk.pop_back();
      stk.push_back({c, count + 1});
    }

    string answer = "";
    for (Data &cur : stk) {
      answer += (cur.count + '0');
      answer += cur.c;
    }

    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  string compressedString(string word) {
    string answer = "";

    char before;
    int count = 0;
    for (char &c : word) {
      if (c == before) {
        count++;
        continue;
      }

      while (count > 0) {
        answer += min(count, 9) + '0';
        answer += before;
        count -= 9;
      }

      before = c;
      count = 1;
    }

    while (count > 0) {
      answer += min(count, 9) + '0';
      answer += before;
      count -= 9;
    }

    return answer;
  }
};