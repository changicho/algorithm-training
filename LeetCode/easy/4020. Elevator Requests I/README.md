# 4020. Elevator Requests I

[링크](https://leetcode.com/problems/elevator-requests-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회하며 이동하는 층수를 더할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int elevatorRequests(int n, vector<int>& requests) {
  int answer = 0;
  int cur = 0;

  for (int& r : requests) {
    answer += max(r, cur) - min(r, cur);

    cur = r;
  }
  return answer;
}
```

## 고생한 점
