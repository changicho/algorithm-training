# 452. Minimum Number of Arrows to Burst Balloons

[링크](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 points의 크기를 N이라 하자.

각 좌표를 끝점에 대해 정렬 후, 순회하며 겹치는 부분들마다 묶을 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 시간 복잡도를 사용할 수 있다.

정렬된 points를 순회하며 머지할 때 stack을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

스택을 사용하지 않고 끝점만 비교할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬 & 스택

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     1295     | O(N \* log_2(N)) |    O(N)     |

각 좌표를 다음과 같이 정렬한다.

- 끝점이 작은 순으로 앞서게

이는 각 좌표들을 끝점에 대해 정렬할 경우, 현재 좌표 이전의 좌표들과 현재좌표가 겹칠 가능성이 생기기 때문이다.

이후 끝점이 작은 순부터 순회하며 겹치는 부분에 대해 스택에 삽입한다.

이 때 스택이 비어있지 않은 경우 스택의 top과 현재 구간이 겹치는지 비교하고 겹칠경우 겹치는 부분만 스택에 삽입한다.

```cpp
bool isOverlapped(vector<int> &a, vector<int> &b) {
  return a.back() >= b.front();
}

int findMinArrowShots(vector<vector<int>> &points) {
  sort(points.begin(), points.end(),
        [](vector<int> &a, vector<int> &b) { return a.back() < b.back(); });

  stack<vector<int>> stk;
  for (vector<int> &p : points) {
    if (!stk.empty() && isOverlapped(stk.top(), p)) {
      vector<int> temp = stk.top();
      stk.pop();

      stk.push({p.front(), temp.back()});
    } else {
      stk.push(p);
    }
  }

  return stk.size();
}
```

## 고생한 점
