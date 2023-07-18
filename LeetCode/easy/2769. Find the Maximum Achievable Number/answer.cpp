#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int theMaximumAchievableX(int num, int t) { return num + 2 * t; }
};