#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use string brute force
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<vector<string>> sequences = {
      {"0"}, {"110", "10"}, {"1110", "10", "10"}, {"11110", "10", "10", "10"}};

  string convert(int num) {
    string ret = "";
    while (num > 0) {
      ret += num % 2 == 1 ? "1" : "0";
      num /= 2;
    }
    while (ret.length() < 8) {
      ret += "0";
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  bool isPrefix(string &prefix, string &data) {
    int size = prefix.size();
    for (int i = 0; i < size; i++) {
      if (prefix[i] != data[i]) return false;
    }
    return true;
  }

 public:
  bool validUtf8(vector<int> &data) {
    vector<string> bytes;
    for (int &d : data) {
      bytes.push_back(convert(d));
    }

    int size = bytes.size();
    int i = 0;
    while (i < size) {
      string cur = bytes[i];

      bool isPass = false;
      for (vector<string> &sequence : sequences) {
        if (!isPrefix(sequence.front(), cur)) continue;

        int temp = i;
        for (string &se : sequence) {
          if (temp >= size) return false;
          if (!isPrefix(se, bytes[temp])) return false;
          temp++;
        }

        i = temp;

        isPass = true;
        break;
      }

      if (!isPass) return false;
    }

    return true;
  }
};

// use bit brute force
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool validUtf8(vector<int> &data) {
    int left = 0;

    for (int num : data) {
      if (left > 0) {
        if ((num >> 6) != 0b10) return false;
        left--;
        continue;
      }

      if ((num >> 5) == 0b110) {
        left = 1;
      } else if ((num >> 4) == 0b1110) {
        left = 2;
      } else if ((num >> 3) == 0b11110) {
        left = 3;
      } else if ((num >> 7)) {
        return false;
      }
    }

    return left == 0;
  }
};