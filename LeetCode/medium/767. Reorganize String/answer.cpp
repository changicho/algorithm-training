#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use priority queue
// time : O(N * log_2(K))
// space : O(N + K)
class Solution {
 private:
  struct Data {
    int count;
    char c;

    bool operator<(const Data &other) const { return count < other.count; }
  };

 public:
  string reorganizeString(string s) {
    vector<int> counts(26, 0);
    for (char &c : s) {
      counts[c - 'a'] = counts[c - 'a'] + 1;
    }

    priority_queue<Data> pq;
    for (int i = 0; i < 26; i++) {
      if (counts[i] > 0) {
        pq.push({counts[i], char(i + 'a')});
      }
    }

    string answer;
    while (!pq.empty()) {
      Data cur = pq.top();
      pq.pop();

      if (answer.empty() || cur.c != answer.back()) {
        answer += cur.c;
        cur.count--;
        if (cur.count > 0) {
          pq.push(cur);
        }

        continue;
      }

      if (pq.empty()) return "";
      // pick from second
      Data second = pq.top();
      pq.pop();
      answer += second.c;
      second.count--;
      if (second.count > 0) {
        pq.push(second);
      }
      pq.push(cur);
    }

    return answer;
  }
};

// use counting odd even
// time : O(N)
// space : O(N)
class Solution {
 public:
  string reorganizeString(string s) {
    vector<int> counts(26, 0);
    for (char &c : s) {
      counts[c - 'a']++;
    }

    int maxCount = 0, letter = 0;
    for (int i = 0; i < counts.size(); i++) {
      if (counts[i] > maxCount) {
        maxCount = counts[i];
        letter = i;
      }
    }

    if (maxCount > (s.length() + 1) / 2) {
      return "";
    }
    string answer = s;

    int index = 0;
    while (counts[letter] != 0) {
      answer[index] = char(letter + 'a');
      index += 2;
      counts[letter]--;
    }

    for (int i = 0; i < counts.size(); i++) {
      while (counts[i] > 0) {
        if (index >= s.length()) {
          index = 1;
        }
        answer[index] = char(i + 'a');
        index += 2;
        counts[i]--;
      }
    }

    return answer;
  }
};
