#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count and multiple

class Solution {
 private:
  int getCount(string &str) {
    int count = 0;
    for (char &c : str) {
      if (c == '1') count++;
    }
    return count;
  }

 public:
  int numberOfBeams(vector<string> &bank) {
    vector<int> beams;

    for (string &b : bank) {
      int count = getCount(b);

      if (count > 0) beams.push_back(count);
    }

    int size = beams.size();

    int answer = 0;
    for (int i = 0; i < size - 1; i++) {
      answer += beams[i] * beams[i + 1];
    }
    return answer;
  }
};