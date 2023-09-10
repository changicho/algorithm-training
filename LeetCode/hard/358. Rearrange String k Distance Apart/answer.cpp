#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use heap
// time : O((N + K) * log_2(K))
// space : O(N + K)
class Solution {
 public:
  string rearrangeString(string s, int k) {
    int size = s.size();
    int counts[26] = {0};
    for (int i = 0; i < size; i++) {
      counts[s[i] - 'a']++;
    }

    priority_queue<pair<int, char>> pq;  // {count, char}
    for (int i = 0; i < 26; i++) {
      if (counts[i]) {
        pq.push({counts[i], i + 'a'});
      }
    }

    string answer;
    queue<pair<int, char>> wait;
    while (answer.size() < size) {
      int index = answer.size();

      if (!wait.empty() && (index - wait.front().first) >= k) {
        auto cur = wait.front();
        wait.pop();
        pq.push({counts[cur.second - 'a'], cur.second});
      }

      if (pq.empty()) {
        return "";
      }

      char currChar = pq.top().second;
      pq.pop();
      answer += currChar;

      counts[currChar - 'a']--;
      if (counts[currChar - 'a'] > 0) {
        wait.push({index, currChar});
      }
    }

    return answer;
  }
};

// use greedy
// time : O(N)
// space : O(N + K)
class Solution {
 public:
  string rearrangeString(string s, int k) {
    unordered_map<char, int> counts;
    int maxCount = 0;
    for (char &c : s) {
      counts[c]++;
      maxCount = max(maxCount, counts[c]);
    }

    unordered_set<char> mostChars;
    unordered_set<char> secondChars;
    for (pair<char, int> charPair : counts) {
      if (charPair.second == maxCount) {
        mostChars.insert(charPair.first);
      } else if (charPair.second == maxCount - 1) {
        secondChars.insert(charPair.first);
      }
    }

    vector<string> segments(maxCount);
    for (int i = 0; i < maxCount; i++) {
      for (char c : mostChars) {
        segments[i] += c;
      }

      if (i < maxCount - 1) {
        for (char c : secondChars) {
          segments[i] += c;
        }
      }
    }

    int index = 0;
    for (pair<char, int> charPair : counts) {
      char currChar = charPair.first;

      if (mostChars.find(currChar) != mostChars.end() ||
          secondChars.find(currChar) != secondChars.end()) {
        continue;
      }

      for (int freq = counts[currChar]; freq > 0; freq--) {
        segments[index] += charPair.first;
        index = (index + 1) % (maxCount - 1);
      }
    }

    for (int i = 0; i < maxCount - 1; i++) {
      if (segments[i].size() < k) {
        return "";
      }
    }

    string answer = "";
    for (string &line : segments) {
      answer += line;
    }
    return answer;
  }
};