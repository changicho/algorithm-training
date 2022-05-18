#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    int size = tiles.size();
    sort(tiles.begin(), tiles.end());

    int maximum = 0;
    int sum = 0;

    int left = 0, right = 0;
    while (maximum < carpetLen && right < size) {
      if (left == right || tiles[right][1] < tiles[left][0] + carpetLen) {
        sum += min(carpetLen, tiles[right][1] - tiles[right][0] + 1);
        maximum = max(maximum, sum);

        right++;
      } else {
        int partial = max(0, tiles[left][0] + carpetLen - tiles[right][0]);
        maximum = max(maximum, sum + partial);
        sum -= (tiles[left][1] - tiles[left][0] + 1);

        left++;
      }
    }

    return maximum;
  }
};

// use binary search with prefix sum
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());
    int size = tiles.size();

    vector<int> prefix(size + 1, 0), ends(size, 0);

    for (int i = 0; i < size; i++) {
      prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
      ends[i] = tiles[i][1];
    }

    int maximum = 0;
    for (int i = 0; i < size; i++) {
      int left = tiles[i][0];
      int right = left + carpetLen - 1;

      int idx = upper_bound(ends.begin(), ends.end(), right) - ends.begin();
      int curSum = prefix[idx] - prefix[i];

      if (idx < size && tiles[idx][0] <= right) {
        curSum += right - tiles[idx][0] + 1;
      }

      maximum = max(maximum, curSum);
    }
    return maximum;
  }
};

// use sliding window
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());

    vector<vector<int>> arr;
    for (int i = 0; i < tiles.size(); i++) {
      vector<int> cur = tiles[i];
      while (!arr.empty() && arr.back()[1] + 1 == cur[0]) {
        int beforeLeft = arr.back()[0];
        arr.pop_back();
        cur[0] = beforeLeft;
      }
      arr.push_back(cur);
    }

    int size = arr.size();
    int right = 0;
    int maximum = 0;

    deque<int> windows;

    int curSum = 0;
    for (int left = 0; left < size; left++) {
      int start = arr[left][0];
      int end = start + carpetLen - 1;

      while (!windows.empty() && arr[windows.front()][1] < start) {
        curSum -= arr[windows.front()][1] - arr[windows.front()][0] + 1;
        windows.pop_front();
      }

      while (right < size && arr[right][0] <= end) {
        curSum += arr[right][1] - arr[right][0] + 1;
        windows.push_back(right);
        right++;
      }

      int temp = curSum;
      if (end < arr[windows.back()][1]) {
        temp -= arr[windows.back()][1] - end;
      }

      maximum = max(maximum, temp);
    }

    return maximum;
  }
};
