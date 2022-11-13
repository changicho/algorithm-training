#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(N)
class Solution {
 private:
  string convert(int &num) {
    string ret = "";
    if (num % 3 == 0) {
      ret += "Fizz";
    }
    if (num % 5 == 0) {
      ret += "Buzz";
    }

    if (ret == "") {
      return to_string(num);
    }
    return ret;
  }

 public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer;
    for (int i = 1; i <= n; i++) {
      answer.push_back(convert(i));
    }
    return answer;
  }
};