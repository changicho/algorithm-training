#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use deque
// time : O(N)
// space : O(N)
class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int size = arr.size();

    int maxI = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] > arr[maxI]) {
        maxI = i;
      }
    }

    if (maxI <= k) {
      return arr[maxI];
    }

    deque<int> dq(arr.begin(), arr.end());

    int consecutive = 0;
    int beforeWin = -1;

    while (consecutive < k) {
      int first = dq.front();
      dq.pop_front();
      int second = dq.front();
      dq.pop_front();

      int winner = max(first, second);
      int loser = min(first, second);

      if (winner == arr[maxI]) return winner;

      if (beforeWin == winner) {
        consecutive++;
      } else {
        consecutive = 1;
        beforeWin = winner;
      }

      dq.push_front(winner);
      dq.push_back(loser);
    }

    return beforeWin;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int size = arr.size();

    int beforeMax = arr[0];
    int countLeft = k;
    for (int i = 1; i < size; i++) {
      if (arr[i] > beforeMax) {
        beforeMax = arr[i];
        countLeft = k;
      }
      countLeft--;

      if (countLeft == 0) return beforeMax;
    }

    return beforeMax;
  }
};