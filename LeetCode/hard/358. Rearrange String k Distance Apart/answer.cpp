#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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