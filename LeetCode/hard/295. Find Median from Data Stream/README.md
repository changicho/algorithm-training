# 295. Find Median from Data Stream

[링크](https://leetcode.com/problems/find-median-from-data-stream/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

저장되는 원소의 최대 개수를 N이라 하자.

매번 정렬을 수행해 중앙값을 찾을 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

삽입 정렬을 이용할 경우 삽입할 위치를 찾는데 O(log_2(N))의 시간 복잡도를, 삽입하는데 O(N)의 시간 복잡도를 사용하므로 최종 O(N)의 시간 복잡도를 사용한다.

두 개의 힙을 사용할 경우 수를 넣을 때마다 O(log_2(N))의 시간 복잡도로 중앙값을 찾을 수 있다.

### 공간 복잡도

삽입 정렬을 사용할 경우 배열에 O(N)의 공간 복잡도를 사용한다.

두 개의 힙을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 두개의 힙

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     344      | O(log_2(N)) |    O(N)     |

```cpp
priority_queue<int> lower;
priority_queue<int, vector<int>, greater<int>> higher;
```

```cpp
void addNum(int num) {
  higher.push(num);
  if (!lower.empty() && higher.top() < lower.top()) {
    int num1 = higher.top(), num2 = lower.top();

    higher.pop();
    lower.pop();

    higher.push(num2);
    lower.push(num1);
  }

  if (higher.size() > lower.size()) {
    lower.push(higher.top());
    higher.pop();
  }
}

double findMedian() {
  if (lower.size() > higher.size()) return lower.top();

  int left = lower.top();
  int right = higher.top();

  return (double)(left + right) / 2;
}
```

## 고생한 점
