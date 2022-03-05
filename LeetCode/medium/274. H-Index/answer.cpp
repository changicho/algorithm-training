#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 private:
  bool isValid(int h, vector<int>& citations) {
    int count = 0;
    for (int& c : citations) {
      if (c >= h) count++;
    }
    return count >= h;
  }

 public:
  int hIndex(vector<int>& citations) {
    int size = citations.size();

    int left = 0, right = size + 1;
    int answer = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isValid(mid, citations)) {
        // pick right part
        answer = mid;
        left = mid + 1;
      } else {
        // pick left part
        right = mid;
      }
    }

    return answer;
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < size; i++) {
      if (i + 1 <= citations[i]) {
        answer++;
        continue;
      }
      break;
    }

    return answer;
  }
};

// use counting sort
// time : O(N)
// space : O(N)
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int size = citations.size();
    vector<int> counting(size + 1, 0);

    for (int& c : citations) {
      counting[min(c, size)]++;
    }

    int answer = 0;
    int sum = 0;
    for (int i = size; i >= 1; i--) {
      sum += counting[i];
      if (sum >= i) {
        answer = i;
        break;
      }
    }

    return answer;
  }
};