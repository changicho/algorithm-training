# 2549. Count Distinct Numbers on Board

[링크](https://leetcode.com/problems/count-distinct-numbers-on-board/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력 받은 수를 N이라 하자. (N <= 100)

각 과정을 직접 구할 경우 각 수마다 순회를 한번씩 하므로 O(N^2)의 시간 복잡도를 사용한다.

수학적인 방법을 이용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션을 수행할 경우 최대 N개의 수를 방문하므로 중복 제거를 위해 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |   O(N^2)    |    O(N)     |

BFS를 이용해 시뮬레이션을 진행한다.

이 때 중복되는 경우를 방지하기 위해 방문 처리한다.

```cpp
int distinctIntegers(int n) {
  queue<int> board;
  board.push(n);

  unordered_set<int> answer;
  answer.insert(n);

  while (!board.empty()) {
    for (int i = 1; i <= board.front(); i++) {
      if (board.front() % i == 1) {
        if (answer.count(i) > 0) continue;
        board.push(i);
        answer.insert(i);
      }
    }
    board.pop();
  }

  return answer.size();
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

1부터 N가지의 수 중에서 현재 수를 X라 하자.

1 ~ X의 값 중 X와의 나머지가 1인 수들을 X`들이라 하자.

여기서 X-1은 무조건 X`이다.

이를 반복할 경우 X-1, X-2, X-3 ... 은 모두 현재단계 또는 다음단계의 X`에 포함됨을 알 수 있다.

따라서 일반적인 경우 N-1이 정답이다.

만약 N이 1인 경우는 이미 보드에 1이 포함되어 있으므로 1을 반환한다.

```cpp
int distinctIntegers(int n) {
  if (n == 1) return 1;
  return n - 1;
}
```

## 고생한 점
