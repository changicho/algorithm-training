#include <vector>

long long sum(std::vector<int> &a) {
  long long ans = 0;

  for (int i : a) {
    ans += i;
  }

  return ans;
}
