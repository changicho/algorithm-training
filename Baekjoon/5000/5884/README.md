# 감시 카메라

[링크](https://www.acmicpc.net/problem/5884)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| 골드 IV |   46.503%   |       1       |

## 설계

### 시간 복잡도

좌표의 수를 N이라 하자. (N <= 50,000)

정답은 y축 3개, y축 2개 x축 1개, y축 1개 x축 2개, x축 3개인 경우로 나눌 수 있다.

여기서 특정 축에 선을 그었을 때 나머지 남은 좌표들을 직교한 다른 2개의 직선에 포함시킬 수 있는지 판단한다.

이를 hash set으로 구현할 경우 시간 복잡도는 O(N^2)며 이는 제한시간 내에 불가능하다.

각 좌표를 y에 대해 정렬한 후 y가 같은 것들을 묶어서 처리한다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표별 x, y를 빠르게 접근하기 위해 hash set, hash map을 사용할 수 있다. 이에 O(N)의 공간 복잡도를 사용한다.

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

## 정렬 & hash map

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(N)) |    O(N)     |

정답은 직선이 y축 3개, y축 2개 x축 1개, y축 1개 x축 2개, x축 3개인 경우로 나눌 수 있다.

y축에 직선을 우선 긋는 경우를 생각해보자.

만약 각 좌표들의 y축의 종류의 수가 3개 이하인 경우 정답이 될 수 있다.

그 외의 경우 특정 y축에 직선을 그었을 때 남은 x좌표의 수가 2개 이하인 경우 정답이 될 수 있다.

이를 위해 각 좌표들을 y축에 대해 정렬한 후 y가 같은 것들을 묶어서 처리한다.

좌표들의 x좌표의 갯수들을 count하고, 각 y축에 속한 좌표들의 x좌표들을 저장한다.

이후 현재 직선이 지나가는 y축에 속한 x좌표들의 갯수를 감소시키고, 남은 x좌표의 수가 2개 이하인지 판단한다.

아닌경우 현재 직선이 지나가는 y축에 속한 x좌표들의 갯수를 증가시켜 복원한다.

```cpp
struct Axis {
  int y, x;
};

bool check(vector<Axis> &axises) {
  int size = axises.size();

  unordered_set<int> ys;
  unordered_map<int, vector<int>> y2x;
  unordered_map<int, int> counts;

  for (Axis &cur : axises) {
    ys.insert(cur.y);
    y2x[cur.y].push_back(cur.x);
    counts[cur.x]++;
  }

  if (ys.size() <= 3) return true;

  // pick one y line
  for (int y : ys) {
    for (int x : y2x[y]) {
      counts[x]--;
      if (counts[x] == 0) counts.erase(x);
    }

    if (counts.size() <= 2) return true;

    for (int x : y2x[y]) {
      counts[x]++;
    }
  }
  return false;
}

bool solution(vector<Axis> &axises) {
  vector<Axis> reversed;
  for (Axis &cur : axises) {
    reversed.push_back({cur.x, cur.y});
  }

  return check(axises) || check(reversed);
}
```

## 고생한 점
