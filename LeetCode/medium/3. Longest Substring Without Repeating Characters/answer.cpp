#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int count = 0;
    set<char> visited;

    for (int start = 0, end = 0; end < s.length(); end++) {
      char cur = s[end];
      while (visited.find(cur) != visited.end() && start < end) {
        char target = s[start];
        start += 1;
        visited.erase(target);
      }

      visited.insert(cur);

      count = max(count, (int)visited.size());
    }

    return count;
  }
};

// use array

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int count = 0;
    int temp_count = 0;
    bool visited[128] = {
        false,
    };

    for (int start = 0, end = 0; end < s.length(); end++) {
      char cur = s[end];
      while (visited[cur] && start < end) {
        char target = s[start];
        start += 1;
        if (visited[target]) {
          visited[target] = false;
          temp_count -= 1;
        }
      }

      visited[cur] = true;
      temp_count += 1;

      count = max(count, temp_count);
    }

    return count;
  }
};

// use end index

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int myMap[128] = {
        0,
    };

    int res = 0;
    int start = 0;
    for (int end = 0; end < s.size(); end++) {
      if (myMap[s[end]] != 0) {
        start = max(start, myMap[s[end]]);
      }
      myMap[s[end]] = end + 1;

      res = max(res, end - start + 1);
    }

    return res;
  }
};