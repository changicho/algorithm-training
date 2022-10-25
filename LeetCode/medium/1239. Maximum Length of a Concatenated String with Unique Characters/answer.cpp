#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force DFS
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  bool hasWord(unordered_set<char> &counts, string &word) {
    for (char &c : word) {
      if (counts.count(c)) {
        return true;
      }
    }
    return false;
  }

  bool isDuplicated(string &word) {
    unordered_set<char> counts;
    for (char &c : word) {
      if (counts.count(c) > 0) {
        return true;
      }
      counts.insert(c);
    }
    return false;
  }

  void recursive(int index, vector<string> &arr, unordered_set<char> &counts) {
    int size = arr.size();
    if (index == size) {
      answer = max(answer, (int)counts.size());
      return;
    }

    if (!hasWord(counts, arr[index]) && !isDuplicated(arr[index])) {
      for (char &c : arr[index]) {
        counts.insert(c);
      }
      recursive(index + 1, arr, counts);
      for (char &c : arr[index]) {
        counts.erase(c);
      }
    }
    recursive(index + 1, arr, counts);
  }

 public:
  int maxLength(vector<string> &arr) {
    unordered_set<char> counts;

    recursive(0, arr, counts);

    return answer;
  }
};

// use brute force DFS (bit)
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  int getLength(int bit) {
    int length = 0;
    while (bit > 0) {
      length += bit % 2;
      bit /= 2;
    }
    return length;
  }

  int convertBit(string &word) {
    int bit = 0;
    for (char &c : word) {
      int cur = (1 << (c - 'a'));
      if ((bit & cur) > 0) return -1;
      bit |= cur;
    }
    return bit;
  }

  void recursive(int index, vector<string> &arr, int bit) {
    int size = arr.size();

    if (index == size) {
      answer = max(answer, getLength(bit));

      return;
    }

    recursive(index + 1, arr, bit);
    int converted = convertBit(arr[index]);
    if (converted == -1) return;
    if (bit & converted) return;
    bit |= converted;
    recursive(index + 1, arr, bit);
  }

 public:
  int maxLength(vector<string> &arr) {
    recursive(0, arr, 0);

    return answer;
  }
};