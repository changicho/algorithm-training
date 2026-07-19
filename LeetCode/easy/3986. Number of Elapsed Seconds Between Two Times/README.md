# 3986. Number of Elapsed Seconds Between Two Times

[링크](https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 시간을 숫자로 변환하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

시간 변환에 O(1)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

입력 포멧을 초단위로 변환 후 시작시간과 끝시간의 차이를 구한다.

```cpp
int convert(string time) {
  int ret = 0;

  ret += (time[6] - '0') * 10 + (time[7] - '0');
  ret += ((time[3] - '0') * 10 + (time[4] - '0')) * 60;
  ret += ((time[0] - '0') * 10 + (time[1] - '0')) * 60 * 60;

  return ret;
}

int secondsBetweenTimes(string startTime, string endTime) {
  return convert(endTime) - convert(startTime);
}
```

## 고생한 점
