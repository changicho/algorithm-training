#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count match (sliding window)

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int s1Length = s1.length(), s2Length = s2.length();
    if (s1Length > s2Length) return false;

    vector<int> s1map(26, 0), s2map(26, 0);
    for (int i = 0; i < s1Length; i++) {
      s1map[s1[i] - 'a']++;
    }

    int limit = s2Length - s1Length;
    for (int start = 0; start <= limit; start++) {
      fill(s2map.begin(), s2map.end(), 0);
      for (int index = 0; index < s1Length; index++) {
        s2map[s2[start + index] - 'a']++;
      }

      if (s1map.size() == s2map.size() &&
          equal(s1map.begin(), s1map.end(), s2map.begin()))
        return true;
    }
    return false;
  }
};

// use optimized count match (sliding window)

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;
    vector<int> s1map(26, 0), s2map(26, 0);

    for (int i = 0; i < s1.length(); i++) {
      s1map[s1[i] - 'a']++;
      s2map[s2[i] - 'a']++;
    }
    for (int i = 0; i < s2.length() - s1.length(); i++) {
      if (s1map.size() == s2map.size() &&
          equal(s1map.begin(), s1map.end(), s2map.begin()))
        return true;

      s2map[s2[i + s1.length()] - 'a']++;
      s2map[s2[i] - 'a']--;
    }
    return s1map.size() == s2map.size() &&
           equal(s1map.begin(), s1map.end(), s2map.begin());
  }
};