# Synchronizing Clocks

[링크](https://algospot.com/judge/problem/read/CLOCKSYNC)

| 정답률(\_%) |
| :---------: |
|     39      |

## 설계

### 시간 복잡도

시계의 갯수는 총 16개, 스위치는 총 10개 이다.

각 스위치를 4번 누를 경우 한번도 누르지 않은 것과 동일하다.

따라서 스위치를 눌러 만들 수 있는 경우의 수는 4^10가지 이다.

각 과정마다 시계를 비교하는데 O(16)의 시간 복잡도를 사용한다.

따라서 모든 경우를 비교하는데 총 시간 복잡도는 O(16 \* 4^10)이다.

### 공간 복잡도

DFS를 이용해 구현할 경우 call stack에 최대 O(10)의 공간 복잡도를 사용한다.

각 경우마다 시계의 상태를 저장해야 하므로 O(16)의 공간 복잡도를 사용한다.

BFS로 구현할 경우 메모리 초과가 발생한다. (모든 경우인 O(4^10)을 큐에 넣어 발생하는 것으로 추정)

## DFS

| 수행시간(ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|    3940ms    | O(16 \* 4^10) | O(16 \* 10) |

각 스위치에 대해서 0~3번까지 누른 상태에 대해 분기를 탐색한다.

```cpp
vector<vector<int>> switches = {
    {0, 1, 2},         {3, 7, 9, 11},   {4, 10, 14, 15}, {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12}, {0, 2, 14, 15},  {3, 14, 15},     {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},   {3, 4, 5, 9, 13}};

bool isAllUpside(vector<int> &clocks) {
  for (int i = 0; i < 16; i++) {
    if (clocks[i] != 0) return false;
  }
  return true;
}

void recursive(int index, vector<int> clocks, int count, int &answer) {
  if (isAllUpside(clocks)) {
    if (answer == -1) {
      answer = count;
    }
    answer = min(count, answer);
  }

  if (index == 10) {
    return;
  }

  recursive(index + 1, clocks, count, answer);
  for (int i = 0; i < 3; i++) {
    for (int &target : switches[index]) {
      clocks[target] += 3;
      clocks[target] %= 12;
    }
    count++;

    recursive(index + 1, clocks, count, answer);
  }
}

int solution(vector<int> &clocks) {
  int answer = -1;

  recursive(0, clocks, 0, answer);

  return answer;
}
```

## 고생한 점

BFS로 구현하면 터진다. 아마 c++에서 기본으로 사용하는 메모리 + 큐 때문에 초과하는것으로 추정됨.

스위치를 4번 누르면 초기상태로 돌아가는것을 처리하지 않는 경우 시간복잡도 초과가 발생한다.
