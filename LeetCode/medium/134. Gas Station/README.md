# 134. Gas Station

[링크](https://leetcode.com/problems/gas-station/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

브루트 포스 방법으로 직접 계산할 경우 시간 복잡도는 O(N^2)이다. 여기서 N은 최대 10^4이므로 제한시간 내에 아슬아슬하다.

투 포인터를 이용해 문제를 최적화해 풀이할 수 있다. 이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

시간 복잡도를 최적화 하기 위한 별도의 공간 복잡도가 필요하지 않다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     200      |   O(N^2)    |    O(1)     |

각 index마다 직접 한바퀴 루프를 돌 수 있는지 검사한다.

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int size = gas.size();

  for (int index = 0; index < size; index++) {
    if (canLoop(gas, cost, index)) return index;
  }
  return -1;
}

bool canLoop(vector<int>& gas, vector<int>& cost, int start) {
  int size = gas.size();
  int index = start;
  int remain = gas[start];

  while (true) {
    remain -= cost[index];
    index = (index + 1) % size;
    if (remain < 0) return false;
    remain += gas[index];
    if (index == start) break;
  }
  return true;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

시작점과 끝점에 대해서 투 포인터를 수행한다.

한 점에서 도달할 수 있는 최대 위치까지 탐색을 진행하고, 불가능한 경우 시작점을 옮긴다.

현재 시작 위치에서 끝위치를 이동시키는 중에 루프가 불가능한 경우 시작 위치를 옮기고 이전에 탐색한 범위만큼을 재사용한다.

이 때 문제에서 주어지는 한번의 순회가 가능한 답은 유일하다.

따라서 시작 위치와 끝 위치를 옮겼을 때 정답은 한가지 경우만 나온다.

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int size = gas.size();

  int left = size - 1, right = 0;
  int sum = gas[left] - cost[left];

  while (left > right) {
    if (sum >= 0) {
      sum += gas[right] - cost[right];
      right++;
    } else {
      left--;
      sum += gas[left] - cost[left];
    }
  }

  if (sum >= 0) return left;
  return -1;
}
```

## 고생한 점
