# 2409. Count Days Spent Together

[링크](https://leetcode.com/problems/count-days-spent-together/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열을 변화하는데 O(1)의 시간 복잡도를 사용한다.

이를 이용해 정답을 판단하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자열을 변환하는데 O(1)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

각 문자열을 실제 일수로 변환한다.

- 이미 지난 월들에 대한 일수를 더한다.
- 현재 일수를 더한다

이후 두 구간을 비교해 겹치는 구간을 판단한다.

- 두 구간중 늦게 시작하는 시간과
- 두 구간중 빨리 끝나는 시간을 비교한다.

```cpp
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int convert(string date) {
  int month = (date[0] - '0') * 10 + date[1] - '0';
  int day = (date[3] - '0') * 10 + date[4] - '0';

  int ret = 0;
  for (int i = 0; i < month - 1; i++) {
    ret += days[i];
  }
  ret += day;

  return ret;
}

int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
  int start = max(convert(arriveAlice), convert(arriveBob));
  int end = min(convert(leaveAlice), convert(leaveBob));

  if (end < start) return 0;
  return end - start + 1;
}
```

## 고생한 점
