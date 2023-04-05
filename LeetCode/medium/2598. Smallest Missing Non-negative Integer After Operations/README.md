# 2598. Smallest Missing Non-negative Integer After Operations

[링크](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. (N <= 1e5)

num의 범위는 -1e9 ~ 1e9 이다.

각 숫자는 value만큼 더하거나 뺄 수 있으며 이를 여러번 반복 가능하다.

각 수를 순회하며 나머지 정리에 따라서 그룹으로 묶을 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

이후 각 그룹별로 채울 수 있는 수들을 채운 뒤 남은 수를 선택한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 value로 나눈 나머지들을 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     247      |    O(N)     |    O(N)     |

nums의 각 숫자들에 value를 더하거나 뺄 수 있다.

이 경우 다음 수 A, B가 다음 관계를 만족할 때 두 수는 같은 수로 만들 수 있다.

- A = B + X \* value
- X는 정수

따라서 입력받은 수들을 value로 나눈 나머지를 구하고 (양수) 이들을 그룹으로 묶을 수 있다.

각 그룹들의 갯수를 세고, 각 갯수들 중 가장 작은 값을 구한다. (이 때 나머지의 count가 0인 경우도 포함한다.)

이 값이 0부터 채울 수 있는 수들의 loop가 된다.

이를 이용해 시작점을 설정하고, 각 그룹을 순회하며 시작 위치를 찾는다.

```cpp
int findSmallestInteger(vector<int> &nums, int value) {
  unordered_map<int, int> mods;
  for (int i = 0; i < value; i++) {
    mods[i] = 0;
  }

  for (int &num : nums) {
    int mod = num % value;
    if (mod < 0) mod += value;
    mods[mod]++;
  }

  int loopCount = INT_MAX;
  for (auto &[key, val] : mods) {
    loopCount = min(loopCount, val);
  }

  int start = (loopCount)*value;
  for (auto &[key, val] : mods) {
    val -= loopCount;
  }
  for (int i = 0; i < value; i++) {
    if (mods[i] == 0) return i + start;
  }
  return 0;
}
```

## 고생한 점
