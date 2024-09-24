#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sort & two pointers
// time : O(N * log_(N))
// space : O(N)
class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int size = deck.size();
    vector<int> answer(size, -1);
    bool skip = false;
    int deckI = 0;
    int answerI = 0;

    sort(deck.begin(), deck.end());

    while (deckI < size) {
      if (answer[answerI] == -1) {
        if (!skip) {
          answer[answerI] = deck[deckI];
          deckI++;
        }

        skip = !skip;
      }

      answerI = (answerI + 1) % size;
    }
    return answer;
  }
};

// use sort & queue
// time : O(N * log_(N))
// space : O(N)
class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int size = deck.size();
    queue<int> q;

    for (int i = 0; i < size; i++) {
      q.push(i);
    }

    sort(deck.begin(), deck.end());

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      answer[q.front()] = deck[i];
      q.pop();

      if (!q.empty()) {
        q.push(q.front());
        q.pop();
      }
    }

    return answer;
  }
};