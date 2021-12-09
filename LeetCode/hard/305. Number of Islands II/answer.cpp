#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use union find

class Solution {
 private:
  // data structure definition
  vector<int> parents;
  // we use count variable to find parents number O(1)
  int count = 0;

  // when we set parent, increase count
  void setParent(int node) {
    parents[node] = node;
    count += 1;
  }

  int find(int a) {
    if (parents[a] == a) return a;

    return parents[a] = find(parents[a]);
  }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    // if a, b has same parent return
    if (a == b) return;

    // set lower value to be parent
    if (a > b) swap(a, b);
    parents[b] = a;
    // we merged it so decrease count
    count -= 1;
  }

  // definition of directions
  vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
    int size = m * n;
    // initialize parents. -1 means there are no island in that index (axis)
    parents.resize(size, -1);

    vector<int> answer;
    // iterate all position
    for (vector<int> &position : positions) {
      int y = position[0], x = position[1];
      // convert axis to index
      int index = y * n + x;

      // if there are only island in that axis, skip it
      if (parents[index] != -1) {
        answer.push_back(count);
        continue;
      }
      // make parent
      setParent(index);

      // iterate 4 direction
      for (vector<int> &dir : dirs) {
        int nextY = dir[0] + y;
        int nextX = dir[1] + x;

        int nextIndex = nextY * n + nextX;

        if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n) continue;
        // if there are no island in that axis
        if (parents[nextIndex] == -1) continue;

        // if next axis is valid, merge it
        merge(index, nextIndex);
      }

      // push current count to answer
      answer.push_back(count);
    }

    return answer;
  }
};