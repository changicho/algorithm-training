#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries,
                   vector<int> pickups) {
  long long answer = 0;

  while (deliveries.size() || pickups.size()) {
    while (deliveries.size() && deliveries.back() == 0) {
      deliveries.pop_back();
    }
    while (pickups.size() && pickups.back() == 0) {
      pickups.pop_back();
    }

    int boxCount = cap;
    int emptyCount = cap;

    int dist = max(deliveries.size(), pickups.size());
    answer += dist * 2;
    while (!deliveries.empty() && boxCount > 0) {
      deliveries[deliveries.size() - 1] -= boxCount;
      boxCount = 0;
      if (deliveries[deliveries.size() - 1] < 0) {
        boxCount = abs(deliveries[deliveries.size() - 1]);
        deliveries.pop_back();
      }
    }

    while (!pickups.empty() && emptyCount > 0) {
      pickups[pickups.size() - 1] -= emptyCount;
      emptyCount = 0;

      if (pickups[pickups.size() - 1] < 0) {
        emptyCount = abs(pickups[pickups.size() - 1]);
        pickups.pop_back();
      }
    }
  }

  return answer;
}