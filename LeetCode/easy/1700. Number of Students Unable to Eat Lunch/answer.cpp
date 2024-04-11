#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue, sandwichQueue;
    for (int& s : students) {
      studentQueue.push(s);
    }
    for (int& s : sandwiches) {
      sandwichQueue.push(s);
    }

    int waitCount = 0;
    while (!studentQueue.empty()) {
      if (studentQueue.front() == sandwichQueue.front()) {
        waitCount = 0;
        studentQueue.pop();
        sandwichQueue.pop();
      } else {
        studentQueue.push(studentQueue.front());
        studentQueue.pop();
        waitCount++;
      }

      if (waitCount == studentQueue.size()) break;
    }
    return studentQueue.size();
  }
};