#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    int size1 = firstList.size(), size2 = secondList.size();
    int idx1 = 0, idx2 = 0;
    vector<vector<int>> answer;

    while (idx1 < size1 && idx2 < size2) {
      vector<int> target1 = firstList[idx1];
      vector<int> target2 = secondList[idx2];

      // overlapped
      if (target1[0] <= target2[1] && target2[0] <= target1[1]) {
        int from = max(target1[0], target2[0]);
        int to = min(target1[1], target2[1]);

        answer.push_back({from, to});
      }

      if (target1[1] < target2[1]) {
        idx1++;
      } else {
        idx2++;
      }
    }

    return answer;
  }
};

// use two pointer with explain

class Solution {
 private:
  // [1,5], [5,10]. the intersection is [5,5]
  // hasIntersection(vector<int> a, vector<int> b)
  // if(a[0] <= b[1] && b[0] <= a[1]) true
  // false
  bool hasIntersection(vector<int>& a, vector<int>& b) {
    // has intersection case
    if (a[0] <= b[1] && b[0] <= a[1]) return true;
    // has not intersection case
    return false;
  }

  // getIntersection(vector<int> a, vector<int> b)
  // return maximum of starts ~ minimum of ends
  // return {max(a[0], b[0]), min(a[1],b[1])};
  vector<int> getIntersection(vector<int>& a, vector<int>& b) {
    return {max(a[0], b[0]), min(a[1], b[1])};
  }

 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    // make answer data
    vector<vector<int>> answer;

    // use two pointer
    // index1 = 0, index2 = 0
    int index1 = 0, index2 = 0;
    // do compare while index1 lower than size1 && index2 lower than size2
    while (index1 < firstList.size() && index2 < secondList.size()) {
      // compare firstList[index1] with seocndList[index2]
      if (hasIntersection(firstList[index1], secondList[index2])) {
        // it hasIntersection
        // push intersection to answer
        answer.push_back(
            getIntersection(firstList[index1], secondList[index2]));
      }
      // if not do nothing

      // increase one of index that end faster
      if (firstList[index1][1] < secondList[index2][1]) {
        index1++;
      } else if (firstList[index1][1] > secondList[index2][1]) {
        index2++;
      } else {
        // if firstData and secondData is exactly same
        // increase any of them
        index1++;
      }
    }

    return answer;
  }
};