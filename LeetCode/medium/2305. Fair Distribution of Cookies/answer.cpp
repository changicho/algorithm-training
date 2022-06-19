#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(K^N)
// space : O(N + K)
class Solution {
 private:
  int answer = INT_MAX;

  void recursive(vector<int> &cookies, int index, vector<int> &children) {
    int size = cookies.size();
    int k = children.size();

    if (size == index) {
      int maximum = children.front();

      for (int &n : children) {
        maximum = max(maximum, n);
      }

      answer = min(maximum, answer);
      return;
    }

    for (int i = 0; i < k; i++) {
      children[i] += cookies[index];

      recursive(cookies, index + 1, children);

      children[i] -= cookies[index];
      if (children[i] == 0) break;
    }
  }

 public:
  int distributeCookies(vector<int> &cookies, int k) {
    int size = cookies.size();

    int sum = 0;
    for (int &c : cookies) {
      sum += c;
    }

    vector<int> children(k, 0);

    recursive(cookies, 0, children);

    return answer;
  }
};