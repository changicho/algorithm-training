# 1701. Average Waiting Time

[링크](https://leetcode.com/problems/average-waiting-time/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 customers의 길이를 N이라 하자.

도착시간별로 이미 정렬되어 있으므로 순회를 이용해 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 과정에서 사용하는 공간이 일정하므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     135      |    O(N)     |    O(1)     |

endTime 변수를 사용해 각 과정마다 고객이 기다린 시간을 구한다.

이후 endTime을 갱신한다.

```cpp
double averageWaitingTime(vector<vector<int>>& customers) {
  int endTime = 0;
  long long sum = 0;
  for (vector<int>& c : customers) {
    int a = c[0], t = c[1];

    endTime = max(endTime, a);
    endTime += t;

    sum += endTime - a;
  }

  return (double)sum / customers.size();
}
```

## 고생한 점
