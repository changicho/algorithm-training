#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  vector<int> bits;

  int temp = 1;
  for (int i = 0; i < n; i++) {
    bits.push_back(temp);
    temp *= 2;
  }

  reverse(bits.begin(), bits.end());

  for (int y = 0; y < n; y++) {
    int cur = arr1[y] | arr2[y];

    string line = "";

    for (int bit : bits) {
      if (cur / bit > 0) {
        line += '#';
      } else {
        line += ' ';
      }
      cur %= bit;
    }

    answer.push_back(line);
  }

  return answer;
}