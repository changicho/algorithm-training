# [PCCP 기출문제] 1번 / 붕대 감기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/250137)

| 난이도 |
| :----: |
|  LV1   |

## 설계

### 시간 복잡도

attacks 배열의 크기를 N, 총 시간을 T라 하자.

각 공격을 순회하는 데 O(N)의 시간 복잡도가 소요된다.

각 시간별로 공격을 받는 경우를 탐색해야 하므로 시간 복잡도는 O(T)이다.

### 공간 복잡도

시간별 공격을 저장할 배열을 생성해야 하므로 공간 복잡도는 O(T)이다.

### 순회 (시간)

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(T + N)   |    O(T)     |

각 공격을 시간에 맞게 저장하고, 시간에 따라 공격을 받는 경우를 탐색한다.

각 과정에서 체력을 최대한 회복시키며, 모두 회복한 경우 추가 회복이 제공됨에 유의한다.

```cpp
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
  int answer = health;

  int table[1001] = {
      0,
  };
  for (vector<int> &a : attacks) {
    table[a[0]] = a[1];
  }
  int TIME_LIMIT = attacks.back()[0];

  int count = 0;
  for (int time = 0; time <= TIME_LIMIT; time++) {
    if (table[time] > 0) {
      answer -= table[time];
      count = 0;
    } else if (answer < health) {
      answer += bandage[1];
      count++;

      if (count == bandage[0]) {
        answer += bandage[2];
        count = 0;
      }

      answer = min(answer, health);
    }

    if (answer <= 0) return -1;
  }

  return answer;
}
```

## 고생한 점
