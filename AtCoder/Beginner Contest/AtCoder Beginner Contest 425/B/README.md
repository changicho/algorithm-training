# B - Find Permutation 2

[링크](https://atcoder.jp/contests/abc425/tasks/abc425_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열에서 중복된 양의 정수가 있는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

이후 남은 공간을 채우는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

중복된 양의 정수를 판단하는데 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

중복된 양의 정수가 있는 경우 조건을 만족하는 순열을 만들 수 없다.

그 외의 경우는 남은 공간을 채우면서 순열을 완성하면 조건을 만족할 수 있다.

```cpp
vector<int> solution(int size, vector<int> &nums) {
  vector<int> answer;

  vector<bool> visited(size + 1, false);
  for (int &num : nums) {
    if (num == -1) continue;

    if (visited[num]) return {};

    visited[num] = true;
  }

  int target = 1;
  while (target < size && visited[target]) target++;

  for (int i = 0; i < size && target <= size; i++) {
    if (nums[i] == -1) {
      nums[i] = target;
      target++;
      while (target < size && visited[target]) target++;
    }
  }

  return nums;
}
```

## 고생한 점
