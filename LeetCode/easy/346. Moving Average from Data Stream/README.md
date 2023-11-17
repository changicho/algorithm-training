# 346. Moving Average from Data Stream

[링크](https://leetcode.com/problems/moving-average-from-data-stream/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

현재 저장된 수들의 합과 제일 먼저 빠져나가야 하는 수를 미리 알고 있을 경우 수가 추가되었을 때 O(1)의 시간 복잡도로 평균을 구할 수 있다.

이를 위해 큐를 이용한다.

### 공간 복잡도

큐를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(1)     |    O(N)     |

큐를 이용해 숫자를 삽입된 순서대로 저장하고 이후 N개 이상의 수가 삽입되는 경우 앞에서부터 제거한다.

이 때 수가 저장될 때마다의 합을 저장후 수가 빠져나갈때도 갱신한다.

이 합을 이용해 매번 평균을 구한다.

```cpp
class MovingAverage {
 private:
  queue<int> q;
  double sum = 0;
  int size = 0;

 public:
  MovingAverage(int size) { this->size = size; }

  double next(int val) {
    if (q.size() >= this->size) {
      sum -= q.front();
      q.pop();
    }
    sum += val;
    q.push(val);

    return sum / q.size();
  }
};
```

## 고생한 점
