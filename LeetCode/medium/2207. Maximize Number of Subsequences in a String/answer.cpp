#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy & one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long answer = 0;
    long long first = 0, second = 0;

    // greedy way
    for (char &c : text) {
      if (c == pattern.back()) {
        answer += first;
        second++;
      }
      if (c == pattern.front()) {
        first++;
      }
    }

    return answer + max(first, second);
  }
};

// use greedy & one pass
// time : O(N)
// space : O(N)
class Solution {
 private:
  long long getCount(string text, string pattern) {
    long long result = 0;
    long long count = 0;

    // greedy way
    for (char &c : text) {
      if (c == pattern.back()) {
        result += count;
      }
      if (c == pattern.front()) {
        count++;
      }
    }

    return result;
  }

 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long frontCase = getCount(pattern.front() + text, pattern);
    long long backCase = getCount(text + pattern.back(), pattern);

    return max(frontCase, backCase);
  }
};