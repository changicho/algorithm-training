# 57. Insert Interval

[링크](https://leetcode.com/problems/insert-interval/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

intervals의 최대 길이는 10^4이다. intervals는 겹치는 범위 없이 모든 수가 시작점에 대해서 오름차순으로 정렬되어있다.

따라서 newInterval을 삽입할 위치와, 삽입했을 때 범위를 합치는 연산을 수행하면 된다.

이 경우 한번의 순회로 해결할 수 있으므로 O(N)의 시간 복잡도가 필요하다.

만약 newInterval을 intervals에 합친 뒤 정렬을 수행하고, 범위를 새로 만들 경우 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

정렬을 수행할 경우 별도의 공간이 필요할수도 있다. 이 경우 공간 복잡도는 최대 O(N)이 필요하다.

또한 새로운 배열에 겹친 범위를 합친 값들을 넣는 경우 O(N)의 공간이 필요하다.

순회를 이용할 경우 별도의 공간 복잡도가 필요하지 않다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      32      | O(N \* log_2(N)) |    O(N)     |

newInterval을 intervals에 삽입후 intervals를 정렬한다.

이후 순회하며 겹친 구간들을 합치는 연산을 수행한다.

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<vector<int>> ret;

  intervals.push_back(newInterval);

  sort(intervals.begin(), intervals.end());

  for (vector<int> interval : intervals) {
    if (ret.empty()) {
      ret.push_back(interval);
    } else if (ret.back().back() >= interval.front()) {
      vector<int> cur = ret.back();
      ret.pop_back();

      ret.push_back({cur.front(), max(cur.back(), interval.back())});
    } else {
      ret.push_back(interval);
    }
  }

  return ret;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

newInterval이 들어갈 위치를 찾는다.

이 때 newInterval이 삽입되면서 겹치는 range들을 한꺼번에 찾아준다.

현재 범위의 끝점이 newInterval의 시작점에 겹치기 시작하는 지점을 찾는다.

이 경우 newInterval이 삽입되면서 합쳐지는 범위의 시작점은 현재 범위의 시작점이 된다.

이후 순회를 계속하며 현재 범위의 시작점이 newInterval의 끝점 이하인 경우까지 탐색을 계속한다.

이후 합쳐진 범위를 정답에 삽입한 뒤 나머지 범위들을 차례로 삽입해준다.

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<vector<int>> ret;
  int index = 0;
  int size = intervals.size();

  while (index < size && intervals[index].back() < newInterval.front()) {
    ret.push_back(intervals[index]);
    index++;
  }

  while (index < size && intervals[index].front() <= newInterval.back()) {
    newInterval.front() = min(newInterval.front(), intervals[index].front());
    newInterval.back() = max(newInterval.back(), intervals[index].back());
    index++;
  }
  ret.push_back(newInterval);

  // // other way
  // newInterval.front() = (index == size) ? newInterval.front() : min(newInterval.front(), intervals[index].front());
  // while (index < size && newInterval.back() >= intervals[index].front()) {
  //   index++;
  // }
  // newInterval.back() = (index == 0) ? newInterval.back() : max(intervals[index - 1].back(), newInterval.back());
  // ret.push_back(newInterval);

  while (index < size) {
    ret.push_back(intervals[index]);
    index++;
  }
  return ret;
}
```

## 고생한 점
