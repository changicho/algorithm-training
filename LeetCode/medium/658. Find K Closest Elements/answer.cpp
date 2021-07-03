#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use struct & sort

class Solution {
 private:
  struct Data {
    int diff, origin;

    bool operator<(const Data& b) {
      if (diff < b.diff || diff == b.diff && origin < b.origin) return true;
      return false;
    }
  };

 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<Data> dataArray;
    for (int num : arr) {
      dataArray.push_back({abs(num - x), num});
    }
    sort(dataArray.begin(), dataArray.end());

    vector<int> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(dataArray[i].origin);
    }

    sort(answer.begin(), answer.end());
    return answer;
  }
};

// use sort

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> dataArray;
    for (int num : arr) {
      dataArray.push_back(num);
    }

    sort(dataArray.begin(), dataArray.end(), [&x](int& a, int& b) { return (abs(a - x) < abs(b - x)) || (abs(a - x) == abs(b - x) && a < b); });

    vector<int> answer = {dataArray.begin(), dataArray.begin() + k};
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// use binary search with sliding window

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int size = arr.size();
    if (k == size) return arr;

    int left = 0, right = size - 1, mid = 0;
    while (left <= right) {
      mid = (left + right) / 2;

      if (arr[mid] > x) {
        right = mid - 1;
      } else if (arr[mid] < x) {
        left = mid + 1;
      } else if (arr[mid] == x) {
        break;
      }
    }

    left = max(0, mid - 1), right = left + 1;
    while (right - left - 1 < k) {
      if (left == -1) {
        right += 1;
        continue;
      }
      if (right == size) {
        left -= 1;
        continue;
      }

      if (abs(arr[left] - x) <= abs(arr[right] - x)) {
        left -= 1;
      } else {
        right += 1;
      }
    }

    vector<int> answer;
    for (int i = left + 1; i < right; i++) {
      answer.push_back(arr[i]);
    }
    return answer;
  }
};

// use binary search

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int size = arr.size();
    if (k == size) return arr;

    int left = 0, right = size - k;
    while (left < right) {
      int mid = (left + right) / 2;

      if (x - arr[mid] > arr[mid + k] - x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    vector<int> answer;
    for (int i = left; i < left + k; i++) {
      answer.push_back(arr[i]);
    }
    return answer;
  }
};