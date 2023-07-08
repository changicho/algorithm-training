#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int size = answerKey.size();

    int answer = 0;
    unordered_map<char, int> count;

    for (int right = 0, left = 0; right < size; right++) {
      count[answerKey[right]]++;

      while (min(count['T'], count['F']) > k && left < right) {
        count[answerKey[left]]--;
        left++;
      }

      answer = max(answer, right - left + 1);
    }

    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int answer = 0;
    unordered_map<char, int> count;

    for (int right = 0; right < answerKey.length(); right++) {
      count[answerKey[right]]++;

      int minor = min(count['T'], count['F']);

      if (minor <= k) {
        answer++;
      } else {
        count[answerKey[right - answer]]--;
      }
    }

    return answer;
  }
};

// use binary search
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  bool isValid(string answerKey, int windowSize, int k) {
    int size = answerKey.length();
    unordered_map<char, int> counter;

    for (int i = 0; i < windowSize; i++) {
      char c = answerKey[i];
      counter[c]++;
    }

    if (min(counter['T'], counter['F']) <= k) {
      return true;
    }
    for (int i = windowSize; i < size; i++) {
      char right = answerKey[i];
      counter[right]++;
      char left = answerKey[i - windowSize];
      counter[left]--;

      if (min(counter['T'], counter['F']) <= k) {
        return true;
      }
    }
    return false;
  }

 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int size = answerKey.size();
    int left = k, right = size;

    while (left < right) {
      int mid = (left + right + 1) / 2;

      if (isValid(answerKey, mid, k)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};