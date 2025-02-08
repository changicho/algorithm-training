# D - Stone XOR

[링크](https://atcoder.jp/contests/abc390/tasks/abc390_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 12)

배열의 하나의 값을 빼서 다른 값에 더할 수 있다.

이를 값의 이동으로 생각하며 배열에 존재하는 수에 대해서만 경우의 수를 생각할 수 있다.

(A -> B, B -> A 두 경우를 같다고 생각)

이 경우 B(N)개의 경우가 생길 수 있다. (B는 bell number)

이는 O(4213597) 이므로 제한시간 내에 가능하다.

정답의 유니크한 경우의 수를 구해야 하므로 hash set을 사용한다. 이 경우 O(1)의 시간 복잡도로 중복을 제거할 수 있다.

### 공간 복잡도

정답에 저장하는데 O(4213597)의 공간 복잡도를 사용한다.

입력받은 배열에 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1689     |   O(B(N))   |    O(N)     |

배열의 두 index를 i, j라 하자.

하나의 index를 선택해 해당 값을 0으로 만들고 다른 index에 원래 값을 더한다.

이 경우 다음 2가지 경우가 생긴다

- i -> j
- j -> i

두 경우 배열의 값들은 같으나 index가 다른 경우이다.

정답에는 index는 고려하지 않으므로 해당 경우에 대한 중복을 줄일 수 있다.

이를 위해서 DFS로 index별로 순회하며, 다음과 같은 탐색을 진행한다.

- 현재 index에 대해서 0 ~ (index-1)까지의 값들 중 하나를 선택해 현재 index로 옮긴다. 이후 다음 index를 탐색한다.
- 혹은 현재 값 그대로를 유지하며 다음 index로 넘어간다.

즉 이전까지 순회한 값들을 현재 index에 옮기는 경우와 그대로 두는 경우 두가지로 나눠서 탐색을 진행한다.

이 때 각 과정마다 최종 XOR 값을 계산하며 index가 끝난 경우 정답에 해당 값 hash set에 저장한다.

```cpp
int solution(int size, vector<long long> &nums) {
  unordered_set<long long> us;

  long long result = 0;
  function<void(int)> recursive = [&](int index) {
    if (index == size) {
      us.insert(result);
      return;
    }

    result ^= nums[index];
    recursive(index + 1);
    result ^= nums[index];

    for (int i = 0; i < index; i++) {
      if (nums[i] == 0) {
        continue;
      }

      long long val = nums[i];

      result ^= val;
      nums[i] = 0;
      nums[index] += val;
      result ^= nums[index];

      recursive(index + 1);

      result ^= nums[index];
      nums[i] = val;
      nums[index] -= val;
      result ^= val;
    }
  };

  recursive(0);

  return us.size();
}
```

## 고생한 점
