# 1272. Remove Interval

[링크](https://leetcode.com/problems/remove-interval/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 intervals의 크기를 N이라 하자.

각 interval을 순회하며 삭제되는 구간과 비교하며 정답에 추가한다. 이 때 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      76      |    O(N)     |    O(N)     |

interval과 toBeRemoved 사이의 관계는 다음과 같다.

- 겹치지 않는 경우 : interval이 왼쪽에 있거나 오른쪽에 있는 경우
- toBeRemoved이 interval를 완전히 포함되는 경우
- interval이 toBeRemoved를 완전힘 포함하는 경우
- 일부만 겹치는 경우 : interval이 왼쪽에 겹치거나 오른쪽에 겹치는 경우

겹치지 않는 경우는 두 범위의 시작점과 끝점을 각각 비교해 판단할 수 있다.

모두 겹치는 경우 또한 시작점과 끝점을 비교해 판단할 수 있다.

일부만 겹치는 경우와 interval이 쪼개지는 경우(interval이 toBeRemoved를 완전히 포함하는 경우)는 다음과 같이 판단할 수 있다.

- 왼쪽부분이 겹치는 경우 : interval의 시작점이 toBeRemoved의 시작점보다 작고 끝점이 toBeRemoved의 시작점보다 큰 경우
- 오른쪽 부분이 겹치는 경우 : interval의 시작점이 toBeRemoved의 끝점보다 작고 끝점이 toBeRemoved의 끝점보다 큰 경우

이를 이용해 정답을 구한다.

```cpp
vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
  vector<vector<int>> answer;

  for (vector<int>& interval : intervals) {
    if (interval[1] < toBeRemoved[0] || toBeRemoved[1] < interval[0]) {
      answer.push_back(interval);
    } else if (toBeRemoved[0] <= interval[0] && interval[1] <= toBeRemoved[1]) {
      continue;
    }

    if (toBeRemoved[0] <= interval[1] && interval[0] < toBeRemoved[0]) {
      answer.push_back({interval[0], toBeRemoved[0]});
    }
    if (interval[0] <= toBeRemoved[1] && toBeRemoved[1] < interval[1]) {
      answer.push_back({toBeRemoved[1], interval[1]});
    }
  }

  return answer;
}
```

## 고생한 점
