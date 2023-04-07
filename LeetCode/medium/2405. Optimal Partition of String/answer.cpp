#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int partitionString(string s) {
    bool visited[26] = {
        false,
    };

    int answer = 0;
    for (char &c : s) {
      if (visited[c - 'a']) {
        memset(visited, false, sizeof(visited));

        answer++;
      }

      visited[c - 'a'] = true;
    }
    return answer + 1;
  }
};

// use sliding window with bit mask
// time : O(N)
// space : O(1)
class Solution {
 public:
  int partitionString(string s) {
    int visited = 0;

    int answer = 0;
    for (char &c : s) {
      if (visited & (1 << (c - 'a'))) {
        visited = 0;
        answer++;
      }

      visited |= (1 << c - 'a');
    }
    return answer + 1;
  }
};