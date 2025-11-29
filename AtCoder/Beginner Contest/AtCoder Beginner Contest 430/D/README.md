# D - Neighbor Distance

[링크](https://atcoder.jp/contests/abc430/tasks/abc430_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

각 인원의 좌표를 추가하며, 추가되는 위치에 인접한 좌표들의 거리 차이를 계산한다.

이를 빠르게 찾기 위해 이분 탐색을 사용할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 가지게 된다.

### 공간 복잡도

각 숫자를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색 & 연결 리스트

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     818      | O(N \* log_2(N)) |    O(N)     |

각 숫자를 BST map에 저장하며, 각 숫자에 대한 이전 좌표, 이후 좌표를 저장한다.

이후 각 숫자가 추가될 때 마다 인접한 숫자들과의 거리 차이를 계산하여, 전체 거리의 합을 업데이트 한다.

이 때 맨 끝에 추가되는 경우와, 중간에 추가되는 경우를 구분한다.

```cpp
auto solution(int size, vector<long long> nums) {
  vector<long long> answer;

  map<long long, long long> prevs;
  map<long long, long long> nexts;

  long long sum = 0;

  prevs[0] = INT_MIN;
  prevs[nums[0]] = 0;
  nexts[0] = nums[0];
  nexts[nums[0]] = INT_MAX;

  answer.push_back(nums[0] * 2);
  sum += nums[0] * 2;

  for (int i = 1; i < size; i++) {
    long long num = nums[i];

    auto it = prevs.lower_bound(num);

    if (it == prevs.end()) {
      long long last = prevs.rbegin()->first;

      nexts[last] = num;
      prevs[num] = last;
      nexts[num] = INT_MAX;

      sum += (num - last);

      if (last - prevs[last] > (num - last)) {
        sum -= (last - prevs[last]);
        sum += (num - last);
      }
    } else {
      long long next = it->first;
      long long prev = it->second;

      long long prevCost = min(nexts[prev] - prev, prev - prevs[prev]);
      long long nextCost = min(nexts[next] - next, next - prevs[next]);

      long long newPrevCost = (num - prev);
      long long newNextCost = (next - num);

      if (prevCost > newPrevCost) {
        sum -= prevCost;
        sum += newPrevCost;
      }

      if (nextCost > newNextCost) {
        sum -= nextCost;
        sum += newNextCost;
      }

      sum += min(newPrevCost, newNextCost);

      prevs[num] = prev;
      nexts[prev] = num;
      nexts[num] = next;
      prevs[next] = num;
    }

    answer.push_back(sum);
  }

  return answer;
}
```

## 고생한 점
