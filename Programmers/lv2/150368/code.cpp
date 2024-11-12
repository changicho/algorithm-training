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

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  vector<int> answer = {0, 0};

  vector<int> discounts(emoticons.size(), 0);

  // 1 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것.
  // 2 이모티콘 판매액을 최대한 늘리는 것.
  auto updateAnswer = [&]() {
    int subscribe = 0;
    int cost = 0;

    for (vector<int>& u : users) {
      int target = u[0], limit = u[1];
      int curCost = 0;

      for (int i = 0; i < emoticons.size(); i++) {
        int discount = discounts[i];
        int e = emoticons[i];

        if (discount >= target) {
          curCost += (double)e * ((double)(100 - discount) / 100);
        }
      }

      if (curCost >= limit) {
        subscribe++;
      } else {
        cost += curCost;
      }
    }

    answer = max(answer, {subscribe, cost});
  };

  auto recursive = [&](int index, auto&& recursive) {
    if (index == discounts.size()) {
      updateAnswer();

      return;
    }

    for (int discount = 10; discount <= 40; discount += 10) {
      discounts[index] = discount;
      recursive(index + 1, recursive);
    }
  };

  recursive(0, recursive);

  return answer;
}