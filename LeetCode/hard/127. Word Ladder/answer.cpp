#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words = {wordList.begin(), wordList.end()};
    // edge case: can't reach to endWord
    if (words.find(endWord) == words.end()) return 0;

    int size = words.size();

    queue<string> q;
    q.push(beginWord);
    words.erase(beginWord);

    int step = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        string cur = q.front();
        q.pop();

        if (cur == endWord) {
          return step + 1;
        }

        // find all possible case from current word
        for (char& c : cur) {
          char before = c;
          for (char next = 'a'; next <= 'z'; next++) {
            c = next;

            if (words.find(cur) == words.end()) continue;
            words.erase(cur);

            q.push(cur);
          }
          c = before;
        }
      }
      step++;
    }

    return 0;
  }
};