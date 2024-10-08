#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use two pointer
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<string> split(string &line) {
    stringstream ss(line);
    vector<string> ret;
    string temp;
    while (ss >> temp) {
      ret.push_back(temp);
    }
    return ret;
  }

  bool check(vector<string> &arr1, vector<string> &arr2) {
    int size1 = arr1.size(), size2 = arr2.size();
    int i1 = 0, i2 = 0;

    int diffCount = 0;
    bool isContinuous = false;
    while (i1 < size1) {
      if (i2 < size2 && arr1[i1] == arr2[i2]) {
        i1++;
        i2++;

        isContinuous = false;
      } else {
        if (!isContinuous) {
          isContinuous = true;
          diffCount++;
        }
        i1++;
      }
    }

    return i2 == size2 && diffCount < 2;
  }

 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> arr1 = split(sentence1), arr2 = split(sentence2);
    if (arr1.size() < arr2.size()) swap(arr1, arr2);

    if (check(arr1, arr2)) return true;
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    if (check(arr1, arr2)) return true;
    return false;
  }
};

// use deque
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<string> split(string &line) {
    stringstream ss(line);
    vector<string> ret;
    string temp;
    while (ss >> temp) {
      ret.push_back(temp);
    }
    return ret;
  }

 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> arr1 = split(sentence1), arr2 = split(sentence2);

    deque<string> dq1(arr1.begin(), arr1.end()), dq2(arr2.begin(), arr2.end());

    while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
      dq1.pop_front();
      dq2.pop_front();
    }
    while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
      dq1.pop_back();
      dq2.pop_back();
    }

    return dq1.empty() || dq2.empty();
  }
};