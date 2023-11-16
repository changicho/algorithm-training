#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int size = arr.size();

    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < size; i++) {
      arr[i] = min(arr[i], arr[i - 1] + 1);
    }

    return arr.back();
  }
};

// use counting sort
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int size = arr.size();
    vector<int> counts(size + 1);

    for (int &num : arr) {
      counts[min(num, size)]++;
    }

    int answer = 1;
    for (int num = 2; num <= size; num++) {
      answer = min(answer + counts[num], num);
    }

    return answer;
  }
};