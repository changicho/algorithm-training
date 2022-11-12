#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class StockSpanner {
 private:
  struct Price {
    int price, index;
  };

  stack<Price> stk;
  int index = 0;

 public:
  StockSpanner() { stk.push({INT_MAX, -1}); }

  int next(int price) {
    int count = 0;
    while (stk.top().price <= price) {
      stk.pop();
    };
    int ret = index - stk.top().index;
    stk.push({price, index});
    index++;
    return ret;
  }
};
