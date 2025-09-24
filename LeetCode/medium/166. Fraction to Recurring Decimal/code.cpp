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

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    string answer;

    if (numerator < 0 ^ denominator < 0) {
      answer.append("-");
    }

    long long a = abs((long long)numerator);
    long long b = abs((long long)denominator);

    answer.append(to_string(a / b));

    long long r = a % b;
    if (r == 0) {
      return answer;
    }

    answer.append(".");
    unordered_map<long long, int> map;
    while (r != 0) {
      if (map.count(r) > 0) {
        answer.insert(map[r], "(");
        answer.append(")");
        break;
      }

      map[r] = answer.length();
      r *= 10;
      answer.append(to_string(r / b));
      r %= b;
    }
    return answer;
  }
};