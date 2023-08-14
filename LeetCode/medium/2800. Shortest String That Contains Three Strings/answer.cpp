#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force with string
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  string merge(string a, string b) {
    if (a.find(b) != -1) return a;
    if (b.find(a) != -1) return b;

    int commonL = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b.size() && i + j < a.size(); j++) {
        if (a[i + j] != b[j]) {
          break;
        }
        if (i + j == a.size() - 1) commonL = max(commonL, j + 1);
      }
    }

    string ret = a + b.substr(commonL);

    return ret;
  }

 public:
  string minimumString(string a, string b, string c) {
    vector<int> arr = {0, 1, 2};
    string answer = a + b + c;

    vector<string> targets = {a, b, c};
    do {
      string foo = merge(targets[arr[0]], targets[arr[1]]);
      string cur = merge(foo, targets[arr[2]]);

      if (answer.size() > cur.size()) {
        answer = cur;
      } else if (answer.size() == cur.size()) {
        answer = min(answer, cur);
      }
    } while (next_permutation(arr.begin(), arr.end()));

    return answer;
  }
};

// use brute force with string
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  string merge(string a, string b) {
    if (a.find(b) != -1) return a;
    for (int i = min(size(a), size(b)); i >= 0; i--) {
      if (a.substr(a.size() - i) == b.substr(0, i)) return a + b.substr(i);
    };
    return a + b;
  }
  string merge(string &a, string &b, string &c) {
    return merge(merge(a, b), c);
  }

 public:
  string minimumString(string a, string b, string c) {
    vector<string> arr = {merge(a, b, c), merge(a, c, b), merge(b, a, c),
                          merge(b, c, a), merge(c, a, b), merge(c, b, a)};

    string answer = a + b + c;
    for (string &cur : arr) {
      if (answer.size() > cur.size()) {
        answer = cur;
      } else if (answer.size() == cur.size()) {
        answer = min(answer, cur);
      }
    }

    return answer;
  }
};