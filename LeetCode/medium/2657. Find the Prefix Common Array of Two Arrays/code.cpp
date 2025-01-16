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

// use count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int size = A.size();

    int count[51] = {
        0,
    };

    vector<int> answer(size);
    int common = 0;
    long long aMask = 0, bMask = 0;
    for (int i = 0; i < size; i++) {
      count[A[i]]++;
      if (count[A[i]] == 2) common++;

      count[B[i]]++;
      if (count[B[i]] == 2) common++;

      answer[i] = common;
    }
    return answer;
  }
};

// use count & bit mask
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int size = A.size();

    vector<int> answer(size);
    long long aMask = 0, bMask = 0;
    for (int i = 0; i < size; i++) {
      aMask |= (1LL << A[i]);
      bMask |= (1LL << B[i]);

      long long common = aMask & bMask;

      answer[i] = __builtin_popcountll(common);
    }
    return answer;
  }
};