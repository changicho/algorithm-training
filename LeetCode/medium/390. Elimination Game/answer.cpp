#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force (TLE)
// time : O(N)
// space : O(N)
class Solution {
 public:
  int lastRemaining(int n) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
      arr.push_back(i);
    }

    bool isLeft = true;
    while (arr.size() > 1) {
      vector<int> temp;
      if (isLeft) {
        for (int i = 1; i < arr.size(); i += 2) {
          temp.push_back(arr[i]);
        }
      } else {
        for (int i = arr.size() - 2; i >= 0; i -= 2) {
          temp.push_back(arr[i]);
        }
        reverse(temp.begin(), temp.end());
      }

      isLeft = !isLeft;
      arr = temp;
    }

    return arr.front();
  }
};

// use math
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int lastRemaining(int n) {
    int head = 1, step = 1;
    bool isLeft = true;

    while (n > 1) {
      if (isLeft) {
        head += step;
      } else {
        head += n % 2 == 0 ? 0 : step;
      }

      step *= 2;
      n /= 2;

      isLeft = !isLeft;
    }

    return head;
  }
};

// use math
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 public:
  int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
  }
};