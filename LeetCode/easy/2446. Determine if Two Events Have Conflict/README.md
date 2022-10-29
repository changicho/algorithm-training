# 2446. Determine if Two Events Have Conflict

[링크](https://leetcode.com/problems/determine-if-two-events-have-conflict/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 구간이 겹쳐있는지 판단하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

두 구간이 겹쳐있는지 판단하는 데 O(1)의 공간 복잡도를 사용한다.

### 구간 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

두 구간이 겹쳐있는 경우 다음을 만족한다.

- A.end >= B.start
- B.end >= A.start

이를 이용해 구현하면 다음과 같다.

```cpp
bool haveConflict(vector<string>& event1, vector<string>& event2) {
  return (event1.back() >= event2.front()) &&
          (event2.back() >= event1.front());
}
```

## 고생한 점
