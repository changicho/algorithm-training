# 17611. 직각다각형

[링크](https://www.acmicpc.net/problem/17611)

| 난이도  |
| :-----: |
| 골드 II |

## 설계

### 시간 복잡도

단순직각다각형의 꼭지점의 수를 N이라 하자.

모든 꼭지점을 연속해서 판단하며 각 선분의 길이와 y,x축에 수평인지를 구한다.

이후 각 축마다의 선분의 위치와 길이를 순회하며 가장 많이 겹치는 갯수를 찾는다.

이를 모두 판단할 경우 시간 복잡도는 O(N^2)이다.

정렬과 우선순위 큐를 사용할 경우 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

각 선분을 저장하는데 필요한 공간은 O(N)이다.

우선순위 큐를 사용할 경우 O(N)이 필요하다.

### 정렬 & 우선순위 큐 & 스위핑

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

좌표들을 순회하며 연이은 좌표들로 만들 수 있는 선분의 시작점과 끝점을 저장한다.

이를 y, x축에 대해 각각 저장한다.

이후 각 축에대해 저장된 선분들 중에 가장 많이 겹치는 갯수를 구한다.

겹치는 갯수를 구하기 위해 정렬과 우선순위 큐(min heap)를 사용할 수 있다.

시작점을 기준으로 오름차순 정렬한다.

이후 선분을 순회하며 우선순위 큐의 top과 비교한다.

만약 우선순위 큐의 top이 현재 선분의 시작점보다 작다면, 해당 선분은 겹치지 않으므로 제거한다.

이를 우선순위 큐에 있는 선분이 겹칠 때 까지 반복한다.

각 과정에서 우선순위 큐에 가장 위에 있는 값은 가장 작은 끝점이므로 각 과정에서 겹치지 않을 가능성이 있는 선분들을 제거할 수 있다.

이후 현재 선분의 끝점을 우선순위 큐에 push한다.

각 과정에서 우선순위 큐의 크기중 가장 큰 값을 반환한다.

이를 y, x축에 대해 각각 수행하고, 두 값중 큰 값을 반환한다.

```cpp
struct Axis {
  int x, y;
};

struct Range {
  int from, to;
};

bool isOverlapped(Range &a, Range &b) {
  if (a.to >= b.from && b.to >= a.from) return true;
  return false;
}

int getMaximumOverlapped(vector<Range> &ranges) {
  // min heap of end time
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // sort by begin accending
  sort(ranges.begin(), ranges.end(),
       [](Range &a, Range &b) { return a.from < b.from; });

  int maximum = 0;
  for (Range &i : ranges) {
    int start = i.from, end = i.to;
    while (!minHeap.empty() && minHeap.top() <= start) {
      minHeap.pop();
    }

    minHeap.push(end);
    maximum = max(maximum, (int)minHeap.size());
  }

  return maximum;
}

int solution(int size, vector<Axis> &axises) {
  vector<Range> yRanges, xRanges;
  for (int i = 0; i < size; i++) {
    int next = (i + 1) % size;

    int y = axises[i].y, ny = axises[next].y;
    int x = axises[i].x, nx = axises[next].x;

    if (y == ny) {
      // push x
      xRanges.push_back({min(x, nx), max(x, nx)});
    } else {
      // push y
      yRanges.push_back({min(y, ny), max(y, ny)});
    }
  }

  int yMax = getMaximumOverlapped(yRanges),
      xMax = getMaximumOverlapped(xRanges);

  return max(yMax, xMax);
}
```

## 고생한 점
