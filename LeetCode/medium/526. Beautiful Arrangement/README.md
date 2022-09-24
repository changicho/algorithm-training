# 526. Beautiful Arrangement

[링크](https://leetcode.com/problems/beautiful-arrangement/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

가능한 모든 경우의 수를 구해야 하므로 DFS를 이용해 완전 탐색한다. 이 때 불가능한 경우를 제외하는 backtracking을 수행한다.

이 경우 가능한 경우의 수를 K라고 할 때 O(K)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 백트래킹을 구현할 경우 함수의 호출 스택에 O(K)의 공간 복잡도를 사용한다.

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      75      |    O(K)     |    O(N)     |

각 수는 한번만 사용할 수 있으며, 해당 수를 사용했는지 여부를 bit masking으로 관리할 수 있다.

이후 DFS를 이용해 탐색하며 현재 채워야 하는 index에 넣을 수 있는 경우만 이후 탐색을 진행한다. (백트래킹)

이를 구현하면 다음과 같다.

```cpp
int answer = 0;

void recursive(int n, int index, int &visited) {
  if (index == n) {
    answer++;
    return;
  }

  for (int num = 1; num <= n; num++) {
    if (visited & (1 << num)) continue;

    if (num % (index + 1) == 0 || (index + 1) % num == 0) {
      visited ^= (1 << num);
      recursive(n, index + 1, visited);
      visited ^= (1 << num);
    }
  }
}

int countArrangement(int n) {
  int visited = 0;
  recursive(n, 0, visited);

  return answer;
}
```

## 고생한 점
