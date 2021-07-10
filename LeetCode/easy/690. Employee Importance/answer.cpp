#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> m;

    for (Employee* employee : employees) {
      m[employee->id] = employee;
    }

    int answer = 0;
    queue<Employee*> q;
    if (m[id] != NULL) q.push(m[id]);

    while (!q.empty()) {
      Employee* cur = q.front();
      q.pop();

      answer += cur->importance;

      for (int id : cur->subordinates) {
        q.push(m[id]);
      }
    }

    return answer;
  }
};