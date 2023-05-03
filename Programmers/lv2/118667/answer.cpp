#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefixSum & sliding window
// time : O(N)
// space : O(N)
int getMinimumCost(vector<int> queue1, vector<int> queue2) {
  int size = queue1.size();
  int answer = INT_MAX;

  unordered_map<long long, int> prefixes;

  long long sum = 0;
  for (int n : queue1) {
    sum += n;
  }
  for (int n : queue2) {
    sum += n;
  }

  if (sum % 2 != 0) {
    return INT_MAX;
  }

  long long temp = 0;
  prefixes[0] = 0;
  for (int i = 0; i < size; i++) {
    temp += queue1[i];
    prefixes[temp] = i + 1;
  }

  if (temp == (sum / 2)) {
    return 0;
  }

  temp = 0;
  for (int left = size - 1, right = size - 1; left >= 0; left--) {
    temp += queue2[left];
    // 슬라이딩 윈도우를 이용해 temp가 sum/2 이하가 될 때까지 right를 줄인다.
    while (temp > (sum / 2) && left < right) {
      temp -= queue2[right];
      right--;
    }

    // (sum/2 - temp) 라는 값이 prefixes에 있는가??
    if (right == size - 1) {
      if (prefixes.count((sum / 2) - temp) > 0) {
        int moveCount = prefixes[(sum / 2) - temp] + (left);

        answer = min(answer, moveCount);
      }
    }
    // 일부 구간이 sum/2가 되는 경우
    if (temp == (sum / 2)) {
      // 일부 구간만을 만들기 위해 다른 큐를 전부 비우고, 현재 구간까지 옮긴 뒤
      // 앞의 부분을 다시 뺀다.
      int moveCount = left + (right + 1) + size;

      answer = min(answer, moveCount);
    }
  }

  return answer;
}

int solution(vector<int> queue1, vector<int> queue2) {
  // 두 큐중에 한 큐의 일부 구간이 정답일 수 있으므로 두 경우를 모두 계산한다.
  int answer =
      min(getMinimumCost(queue1, queue2), getMinimumCost(queue2, queue1));

  if (answer == INT_MAX) return -1;
  return answer;
}