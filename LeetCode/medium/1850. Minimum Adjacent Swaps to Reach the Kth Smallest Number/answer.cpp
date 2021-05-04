#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMinSwaps(string num, int k) {
    string original = num;

    for (int i = 0; i < k; i++) {
      next_permutation(num.begin(), num.end());
    }

    return countSwaps(num, original);
  }

  int countSwaps(string current, string target) {
    int length = current.length();
    int index = 0;
    int count = 0;

    while (index < length) {
      int from = index;

      if (current[index] != target[index]) {
        // find first index that target[index] == current[from]
        from = current.find(target[index], index);
      }

      for (int i = from; i > index; i--) {
        swap(current[i], current[i - 1]);
        count += 1;
      }

      index++;
    }
    return count;
  }
};