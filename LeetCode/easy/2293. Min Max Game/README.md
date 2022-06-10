# 2293. Min Max Game

[링크](https://leetcode.com/problems/min-max-game/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

매번 경우를 직접 비교하며 시뮬레이션 할 경우 최종적으로 (2 * N - 1)번 비교하게 된다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

큐를 이용해 비교할 경우 O(N)의 공간 복잡도를 사용한다.

기존에 입력받은 배열을 활용할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색 (시뮬레이션)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

큐를 이용해 각 경우마다 첫번째, 두번째 원소를 비교하며 정답을 구한다.

이 때 매 단계에서 짝수 홀수 번일때 비교 연산이 다르므로, step별로 비교한다.

```cpp
int minMaxGame(vector<int>& nums) {
  queue<int> q;

  for (int& num : nums) {
    q.push(num);
  }
  while (q.size() > 1) {
    int size = q.size();

    for (int i = 0; i < size / 2; i++) {
      int first = q.front();
      q.pop();
      int second = q.front();
      q.pop();

      if (i % 2 == 0) {
        q.push(min(first, second));
      } else {
        q.push(max(first, second));
      }
    }
  }
  return q.front();
}
```

### 완전 탐색 O(1) (시뮬레이션)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

위 방법에서 큐를 이용하지 않고 기존에 입력받은 배열을 이용해 공간 복잡도를 최적화한다.

```cpp
int minMaxGame(vector<int>& nums) {
  for (int size = nums.size(); size > 1; size = (size + 1) / 2) {
    for (int i = 0; i < size / 2; i++) {
      if (i % 2 == 0) {
        nums[i] = min(nums[2 * i], nums[2 * i + 1]);
      } else {
        nums[i] = max(nums[2 * i], nums[2 * i + 1]);
      }
    }
  }
  return nums.front();
}
```

## 고생한 점
