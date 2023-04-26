# Illumination Optimization (4pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cad086)

## 설계

### 시간 복잡도

입력받은 길이를 L, 반지름을 R, 좌표의 갯수를 N이라 하자.

선택한 좌표의 수가 최소가 되도록 전등을 배치하기 위해선 겹치는 범위가 적은 편이 유리하다.

왼쪽부터 현재까지 밝힐 수 있는 좌표의 위치가 존재할 때, 가능한 가장 오른쪽에 있는 좌표를 선택하고 전등을 배치한다.

이 경우 이미 좌표들이 정렬되어 있다면 이분 탐색을 이용해 O(log_2(N))의 시간 복잡도로 각 좌표들을 찾을 수 있다.

또한 각 좌표를 선택 후에는 다시는 선택할 수 없다.

따라서 set을 이용해 좌표들을 저장 후 이분탐색으로 각 좌표를 찾는다.

이 경우 set에 좌표들을 저장하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이를 모든 L을 커버 가능할 때 까지 반복한다.

최악의 경우 모든 좌표를 하나하나 순회해야 하므로 총 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

set에 좌표들을 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### set, 이분 탐색

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(N)) |    O(N)     |

현재까지 빛이 들어오는 좌표의 제일 오른쪽 좌표를 X라 할 때, 현재 선택해야 하는 좌표(전등을 놓을)는 아래를 만족하는 좌표이다.

- (X + R)보다 작은 좌표 중 가장 큰 좌표 (오른쪽에 있는 좌표)

이를 남은 좌표들에 대해 구하기 위해 upper_bound를 이용한다.

upper_bound로 구한 좌표의 prev값이 원하는 좌표이다.

이 때 prev값을 사용하므로, set에 끝값을 설정하기 위해 선택 불가능한 가장 큰 값, 가장 작은 값을 함께 넣어준다.

전구를 배치할 때 왼쪽, 오른쪽 모두 커버가 가능하므로 각 과정마다 (X + R)에 대한 좌표를 탐색한다.

이 때 맨 마지막 좌표에 전구를 놓았을 때 L까지 커버가 가능한 경우 탐색을 종료한다.

```cpp
int solution(int length, int radius, vector<int> &positions) {
  int answer = 0;

  set<int> axises(positions.begin(), positions.end());
  axises.insert(INT_MAX);
  axises.insert(INT_MIN);

  int boundaryEnd = radius;

  while (boundaryEnd < (length + radius)) {
    // boundaryEnd < target
    auto it = prev(axises.upper_bound(boundaryEnd));

    if (it == axises.begin()) return -1;
    int target = *it;
    axises.erase(target);

    answer++;

    if (target + radius >= length) break;
    int nextBoundaryEnd = target + radius * 2;
    boundaryEnd = nextBoundaryEnd;
  }

  return answer;
}
```

## 고생한 점
