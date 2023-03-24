#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use two stack
// time :
// - push : O(1)
// - move : O(S)
// - visit : O(N)
// space : O(N)
class BrowserHistory {
 private:
  stack<string> backs, fronts;

 public:
  BrowserHistory(string homepage) { backs.push(homepage); }

  void visit(string url) {
    backs.push(url);
    while (!fronts.empty()) {
      fronts.pop();
    }
  }

  string back(int steps) {
    int size = backs.size();
    for (int i = 0; i < min(steps, size - 1); i++) {
      fronts.push(backs.top());
      backs.pop();
    }
    return backs.top();
  }

  string forward(int steps) {
    int size = fronts.size();
    for (int i = 0; i < min(steps, size); i++) {
      backs.push(fronts.top());
      fronts.pop();
    }
    return backs.top();
  }
};
