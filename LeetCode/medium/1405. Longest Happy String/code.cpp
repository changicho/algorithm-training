#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use heap
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isTripleSame(char &a, char &b, char &c) { return a == b && b == c; }

 public:
  string longestDiverseString(int a, int b, int c) {
    string answer = "";
    priority_queue<pair<int, char>> pq;

    pq.push({a, 'a'});
    pq.push({b, 'b'});
    pq.push({c, 'c'});

    while (!pq.empty()) {
      int size = answer.size();
      auto first = pq.top();
      pq.pop();

      if (first.first == 0) break;

      if (answer.size() < 2 ||
          !isTripleSame(answer[size - 1], answer[size - 2], first.second)) {
        answer.push_back(first.second);

        pq.push({first.first - 1, first.second});
      } else {
        auto second = pq.top();
        pq.pop();

        if (second.first == 0) break;

        answer.push_back(second.second);

        pq.push({second.first - 1, second.second});
        pq.push(first);
      }
    }

    return answer;
  }
};