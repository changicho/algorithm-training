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

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> getIntersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> us(arr1.begin(), arr1.end());

    vector<int> ret;
    for (int& num : arr2) {
      if (us.count(num)) ret.push_back(num);
    }
    return ret;
  }

 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> newArr = getIntersection(arr1, arr2);
    return getIntersection(newArr, arr3);
  }
};

// use three pointers
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> answer;

    int size1 = arr1.size(), size2 = arr2.size(), size3 = arr3.size();
    int i1 = 0, i2 = 0, i3 = 0;

    while (i1 < size1 && i2 < size2 && i3 < size3) {
      if (arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]) {
        answer.push_back(arr1[i1]);
        i1++;
        i2++;
        i3++;
        continue;
      }

      if (arr1[i1] <= arr2[i2] && arr1[i1] <= arr3[i3]) {
        i1++;
        continue;
      }
      if (arr2[i2] <= arr1[i1] && arr2[i2] <= arr3[i3]) {
        i2++;
        continue;
      }
      if (arr3[i3] <= arr1[i1] && arr3[i3] <= arr2[i2]) {
        i3++;
        continue;
      }
    }
    return answer;
  }
};