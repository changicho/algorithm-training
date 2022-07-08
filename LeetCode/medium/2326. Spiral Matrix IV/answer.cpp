#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// use brute force
// time : O(N * M)
// space : O(N * M)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));

    Axis cur = {0, 0};
    int dir = 0;

    while (head) {
      matrix[cur.y][cur.x] = head->val;
      head = head->next;

      Axis next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};
      // change dir
      if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n ||
          matrix[next.y][next.x] != -1) {
        dir = (dir + 1) % 4;
        next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};
      }
      cur = next;
    }
    return matrix;
  }
};