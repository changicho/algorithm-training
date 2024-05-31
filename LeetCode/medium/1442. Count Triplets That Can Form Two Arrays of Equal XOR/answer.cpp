#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^3)
// space : O(N^2)
class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int size = arr.size();
    int dp[301][301] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      int temp = arr[i];
      dp[i][i] = temp;
      for (int j = i + 1; j < size; j++) {
        temp ^= arr[j];
        dp[i][j] = temp;
      }
    }

    int answer = 0;
    for (int from = 0; from < size; from++) {
      for (int to = from + 1; to < size; to++) {
        for (int mid = from; mid < to; mid++) {
          if (dp[from][mid] == dp[mid + 1][to]) answer++;
        }
      }
    }
    return answer;
  }
};

// use brute force
// time : O(N^3)
// space : O(N^2)
class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int size = arr.size();

    int answer = 0;
    for (int from = 0; from < size; from++) {
      int first = 0;
      for (int mid = from; mid < size; mid++) {
        first ^= arr[mid];

        int second = 0;
        for (int to = mid + 1; to < size; to++) {
          second ^= arr[to];

          if (first == second) answer++;
        }
      }
    }
    return answer;
  }
};

// use prefix
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int size = arr.size();
    vector<int> prefixXOR(size + 1);

    for (int i = 1; i < size + 1; i++) {
      prefixXOR[i] = arr[i - 1] ^ prefixXOR[i - 1];
    }

    int count = 0;

    for (int left = 0; left < size + 1; left++) {
      for (int right = left + 1; right < size + 1; right++) {
        if (prefixXOR[left] == prefixXOR[right]) {
          count += right - left - 1;
        }
      }
    }

    return count;
  }
};

// use prefix one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int size = arr.size();
    int answer = 0;
    int prefix = 0;

    unordered_map<int, int> countMap = {{0, 1}}, totalMap;

    for (int i = 0; i < size; ++i) {
      prefix ^= arr[i];

      answer += countMap[prefix] * i - totalMap[prefix];
      countMap[prefix]++;

      totalMap[prefix] += i + 1;
    }

    return answer;
  }
};