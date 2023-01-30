# 21756. 지우개

[링크](https://www.acmicpc.net/problem/21756)

| 정답률 (%) |  난이도   |
| :--------: | :-------: |
|   58.001   | 브론즈 II |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

시뮬레이션을 이용할 경우 각 과정마다 순회에 N, N/2, N/4 ... 1 번 순회하게 된다.

이를 모두 더하면 2N 이하 이므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 시뮬레이션을 진행할 경우 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 과정마다 시뮬레이션을 직접 수행한다.

```cpp
long long solution(int n) {
  int answer = 0;

  vector<int> before;
  for (int i = 1; i <= n; i++) {
    before.push_back(i);
  }

  while (before.size() > 1) {
    vector<int> cur;
    for (int i = 1; i < before.size(); i += 2) {
      cur.push_back(before[i]);
    }
    before = cur;
  }

  return before.front();
}
```

## 고생한 점
