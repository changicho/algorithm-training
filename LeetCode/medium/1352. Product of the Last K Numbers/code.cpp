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

// use prefix sum
// time : O(1)
// space : O(N)
class ProductOfNumbers {
 private:
  vector<int> prefix;
  int size = 0;

 public:
  ProductOfNumbers() {
    prefix.push_back(1);
    size = 0;
  }

  void add(int num) {
    if (num == 0) {
      prefix = {1};
      size = 0;
    } else {
      prefix.push_back(prefix.back() * num);
      size++;
    }
  }

  int getProduct(int k) {
    if (k > size) return 0;

    return prefix[size] / prefix[size - k];
  }
};