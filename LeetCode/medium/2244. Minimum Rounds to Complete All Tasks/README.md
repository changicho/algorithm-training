# 2244. Minimum Rounds to Complete All Tasks

[링크](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

tasks의 갯수를 N, 유일한 난이도의 갯수를 M이라 하자. (M은 최대 N이 될 수 있다.)

우선 tasks를 순회하며 난이도로 묶고 각 난이도를 count한다. 이 때 hash map을 사용해 시간 복잡도를 O(1)로 각 값을 저장한다.

이후 각 난이도를 2, 3개씩 묶었을 때 최소 묶음 갯수를 정답에 더한다.

이 경우 한 번 순회에 O(N)의 시간 복잡도를 사용하며, 이후 난이도 순회에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 난이도를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### hash map & math & mod

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     281      |    O(N)     |    O(N)     |

task를 2개, 3개씩 묶어서 처리할 수 있으므로 같은 task끼리 count한다.

여기서 task를 처리하지 못하는 경우는 task가 1개인 경우이다.

그 외의 경우는 2와 3의 조합으로 모든 수를 만들 수 있다.

- 3을 2 + 1이라 생각하자.
- 1을 제외한 모든 자연수는 2N, 2N + 1로 나타낼 수 있다.
- 따라서 2와 3의 합으로 표현할 수 있다.

여기서 최소 갯수를 구하는 방법은 다음과 같다.

- 3을 최대한 많이 사용한다.
- 이후 남은 수가 1, 2 인 경우 다음과 같이 조합한다.
- 남은 수가 1인 경우 기존 3을 하나 제거하고 2를 2개 사용한다.
- 남은 수가 2인 경우 2를 더한다.

위 규칙을 일반화 할 경우 남은 수는 다음과 같이 구할 수 있다.

```cpp
int cur = (count + 2) / 3;
```

이를 이용해 구현하면 다음과 같다.

```cpp
int minimumRounds(vector<int> &tasks) {
  unordered_map<int, int> counts;
  for (int &task : tasks) {
    counts[task]++;
  }

  int round = 0;
  for (auto &[key, val] : counts) {
    if (val == 1) return -1;
    // round += val / 3;
    // if (val % 3 != 0) round++;
    round += (val + 2) / 3;
  }
  return round;
}
```

## 고생한 점
