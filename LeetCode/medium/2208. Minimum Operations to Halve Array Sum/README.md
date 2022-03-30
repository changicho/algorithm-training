# 2208. Minimum Operations to Halve Array Sum

[링크](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

각 경우마다 가장 큰 값을 절반으로 나누고 총 합에서 줄어든 만큼 줄인다.

이후 절반으로 나눈 값을 배열에 삽입한다.

이를 맨 처음 총 합의 절반 이하가 되기 직전까지 수행한다.

매 경우마다 최대값을 구해야 하므로 heap을 이용한다. 모든 수로 heap을 구성해야 하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 과정마다 heap의 최대값을 삭제하고 다시 넣는 과정에 O(log_2(N))의 시간 복잡도를 사용한다.

최악의 경우도 N번 이내에 총 합을 절반 이하로 나눌 수 있으므로 이를 최대 N번 반복한다.

따라서 시간 복잡도는 O(N \* log_2(N))이 된다.

### 공간 복잡도

heap을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     343      | O(N \* log_2(N)) |    O(N)     |

처음에 모든 수의 합을 구하며 maxHeap에 각 수를 삽입한다.

이후 현재 합이 처음 합의 절반일 때마다 count를 증가시키며 아래를 연산을 수행한다.

- maxHeap의 최대값을 뽑고 절반으로 나눈다.
- 해당 값만큼 현재 합에서 감소한다.
- 해당 값을 heap에 삽입한다.

이후 연산이 끝나면 count를 반환한다.

```cpp
int halveArray(vector<int>& nums) {
  // O(N)
  priority_queue<double> maxHeap;
  double sum = 0;

  // O(N)
  for (int& n : nums) {
    sum += n;
    // O(log_2(N))
    maxHeap.push(n);
  }

  double curSum = sum;
  int answer = 0;
  // maximum O(N)
  while (curSum > sum / 2) {
    answer++;

    // O(log_2(N))
    double maximum = maxHeap.top();
    maxHeap.pop();
    curSum -= maximum / 2;
    maxHeap.push(maximum / 2);
  }

  return answer;
}
```

## 고생한 점
