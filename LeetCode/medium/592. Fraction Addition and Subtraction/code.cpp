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

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Number {
    int a, b;
  };

  Number trim(Number num) {
    int gcdVal = abs(gcd(num.a, num.b));

    return {num.a / gcdVal, num.b / gcdVal};
  }

  Number add(Number a, Number b) {
    int commonB = a.b * b.b;

    a.a *= commonB / a.b;
    a.b = commonB;

    b.a *= commonB / b.b;
    b.b = commonB;

    return trim({a.a + b.a, a.b});
  }

 public:
  string fractionAddition(string expression) {
    int size = expression.size();

    Number answer = {0, 1};

    int i = 0;
    while (i < size) {
      int digit = +1;
      if (expression[i] == '-') {
        digit = -1;
        i++;
      } else if (expression[i] == '+') {
        i++;
      }

      int a = 0;
      while (i < size && isdigit(expression[i])) {
        a = a * 10 + expression[i] - '0';
        i++;
      }
      if (digit == -1) a *= -1;

      // skip '/'
      i++;

      digit = +1;
      if (expression[i] == '-') {
        digit = -1;
        i++;
      }

      int b = 0;
      while (i < size && isdigit(expression[i])) {
        b = b * 10 + expression[i] - '0';
        i++;
      }
      if (digit == -1) b *= -1;

      answer = add(answer, {a, b});
    }

    return to_string(answer.a) + "/" + to_string(answer.b);
  }
};