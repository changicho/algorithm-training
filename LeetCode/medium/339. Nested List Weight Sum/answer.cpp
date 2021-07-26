#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

// use recursive

class Solution {
 public:
  int depthSum(vector<NestedInteger> &nestedList) {
    return depthSum(nestedList, 1);
  }

 private:
  int depthSum(vector<NestedInteger> const &nestedList, int depth) {
    int sum = 0;

    for (NestedInteger const &cur : nestedList) {
      if (cur.isInteger()) {
        sum += depth * cur.getInteger();
        continue;
      }
      sum += depthSum(cur.getList(), depth + 1);
    }

    return sum;
  }
};