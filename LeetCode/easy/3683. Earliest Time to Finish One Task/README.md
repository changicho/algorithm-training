# 3683. Earliest Time to Finish One Task

[링크](https://leetcode.com/problems/earliest-time-to-finish-one-task/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 tasks의 크기를 N이라 하자.

순회를 이용해 정답을 구할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

순회 후 최대값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

작업이 끝나는 시간은 작업의 시작시간 + 걸리는 시간 이다.

순회를 이용해 이 중 최소값을 구한다.

```cpp
int earliestTime(vector<vector<int>>& tasks) {
  int answer = INT_MAX;
  for (vector<int>& t : tasks) {
    answer = min(answer, t[0] + t[1]);
  }
  return answer;
}
```

## 고생한 점
