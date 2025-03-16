# 2025 프로그래머스 코드챌린지 1차 예선 - 유연근무제


[링크](https://school.programmers.co.kr/learn/courses/30/lessons/388351)

| 난이도 |
| :----: |
|  lv1   |

## 설계

### 시간 복잡도

각 인원의 수를 N이라 하자.

각 인원들의 목표와 인원들의 출근시간을 순회하며 판단한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 시각정보를 유효하게 변환하는데 O(1)의 공간 복잡도를 사용한다.

### 시간 변환

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

시작 요일에 따라 주말의 index를 구한다.

이후 주말을 무시하며 각 인원의 출근시간이 적합한지 판단한다.

```cpp
int convert(int time) {
  int h = time / 100;
  int m = time % 100;

  return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs,
             int startday) {
  startday--;

  int size = schedules.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    int target = convert(schedules[i]) + 10;

    int saturday = (5 - startday + 7) % 7;
    int sunday = (6 - startday + 7) % 7;

    int count = 0;
    for (int d = 0; d < 7; d++) {
      if (d == saturday || d == sunday) continue;

      int t = convert(timelogs[i][d]);

      if (t <= target) count++;
    }

    if (count == 5) answer++;
  }

  return answer;
}
```

## 고생한 점
