#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(2^M)
// space : O(N + M)
class Solution {
 private:
  vector<vector<int>> requests;
  int inDegrees[21] = {
      0,
  };

  int answer = 0;

  int updateBits(int bits, int node) {
    if (inDegrees[node] == 0) {
      bits &= ~(1 << node);
    } else {
      bits |= (1 << node);
    }
    return bits;
  }

  void recursive(int n, int index, int reqCount, int bits) {
    if (index == requests.size()) {
      if (bits != 0) return;

      answer = max(answer, reqCount);
      return;
    }

    int from = requests[index][0], to = requests[index][1];

    // use request case
    inDegrees[from]--;
    inDegrees[to]++;

    bits = updateBits(bits, from);
    bits = updateBits(bits, to);

    recursive(n, index + 1, reqCount + 1, bits);
    inDegrees[from]++;
    inDegrees[to]--;

    bits = updateBits(bits, from);
    bits = updateBits(bits, to);

    // ignore request case
    recursive(n, index + 1, reqCount, bits);
  }

 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    this->requests = requests;
    int bits = 0;
    recursive(n, 0, 0, bits);

    return answer;
  }
};