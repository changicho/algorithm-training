# 2037. Minimum Number of Moves to Seat Everyone

[링크](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기를 N이라 하자.

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 필요하다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      9       | O(N \* log_2(N)) |    O(N)     |

탐욕 알고리즘을 사용해 각 학생들과 자리들의 차이를 최소화한다.

두 배열을 정렬한 뒤, 각 index의 값들에 대해 차이를 구하면 된다.

```cpp
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
  sort(seats.begin(), seats.end());
  sort(students.begin(), students.end());

  int size = seats.size();
  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer += abs(seats[i] - students[i]);
  }
  return answer;
}
```

## 고생한 점
