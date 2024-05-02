# 2441. Largest Positive Integer That Exists With Its Negative

[링크](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 원소를 hash set에 저장하고, 음수 쌍이 있는 양수 중 가장 큰 값을 찾을 수 있다.

이 경우 hash set에 저장하는 순회에 O(N)의 시간 복잡도를 사용한다.

이후 수를 순회하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |    O(N)     |    O(N)     |

nums의 각 원소를 순회하며 hash set에 저장한다.

이후 각 원소를 다시 순회하며 음수 쌍이 있는 양수 중 가장 큰 값을 찾는다.

이를 구현하면 다음과 같다.

```cpp
int findMaxK(vector<int> &nums) {
  unordered_set<int> appears;

  int answer = -1;
  for (int &num : nums) {
    appears.insert(num);
  }

  for (int &num : nums) {
    if (num < 0) continue;

    if (appears.count(-num) > 0) {
      answer = max(answer, num);
    }
  }
  return answer;
}
```

### hash set & one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      |    O(N)     |    O(N)     |

nums의 각 원소를 순회하며 음수인 경우와 양수인 경우, 절대값이 같고 부호가 다른 값이 존재하는 경우 answer를 갱신한다.

이 때 절대값으로 갱신해야 함에 유의한다.

```cpp
int findMaxK(vector<int> &nums) {
  unordered_set<int> us;

  int answer = -1;
  for (int &num : nums) {
    if (us.count(-num)) {
      answer = max(answer, abs(num));
    }
    us.insert(num);
  }
  return answer;
}
```

## 고생한 점
