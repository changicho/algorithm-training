# C - Odd One Subsequence

[링크](https://atcoder.jp/contests/abc429/tasks/abc429_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 숫자를 count하는 데 hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이후 각 숫자의 count를 순회하며 정답을 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### 카운트 (조합)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      29      |    O(N)     |    O(N)     |

숫자 3개를 골라야 하며 이 중 2개는 같은 숫자여야 한다.

각 숫자의 count를 세며, 이 중 2개 이상인 수를 선택하고 나머지 1개를 다른 수를 선택하는 방법을 사용한다.

이 경우 A, B 두 집합을 선택하며 A는 같은 수 2개를 고르고, B는 1개를 고르는 집합이라 하자.

A의 갯수를 X라 할 때 A 중 2개를 고르는 갯수는 (X) \* (X - 1) / 2 가 된다.

나머지 B를 고르는 경우의 수는 N - X가 된다.

이를 이용해 정답을 구한다.

```cpp
auto solution(int size, vector<int>& nums) {
  long long answer = 0;

  unordered_map<int, int> counts;
  for (int& num : nums) {
    counts[num]++;
  }

  for (auto [key, val] : counts) {
    if (val < 2) continue;
    // chose two same
    long long twoCases = (long long)val * (val - 1) / 2;

    answer += twoCases * (size - val);
  }

  return answer;
}
```

## 고생한 점

중간에 int형을 벗어난 연산이 존재한다.