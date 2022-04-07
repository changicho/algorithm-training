# 2224. Minimum Number of Operations to Convert Time

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 시간을 minute로 모두 변환한 뒤 operation을 수행한다.

이 때 가능한 가장 큰 수들부터 더해나간다. (그리디 알고리즘)

이 경우 최악의 경우도 O(1500) 이내에 수행되므로 시간 복잡도는 O(1)이다.

### 공간 복잡도

그리디 알고리즘을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

입력받은 시간을 분으로 변환한다.

이후 가능한 가장 큰 값을 더하며 step을 센다.

이를 구현하면 다음과 같다.

```cpp
int convert(string time) {
  int minutes = ((time[0] - '0') * 10 + time[1] - '0') * 60 +
                (time[3] - '0') * 10 + time[4] - '0';
  return minutes;
}

int convertTime(string current, string correct) {
  int curTime = convert(current), corTime = convert(correct);

  vector<int> times = {60, 15, 5, 1};

  int step = 0;
  for (int &time : times) {
    while (curTime + time <= corTime) {
      step++;
      curTime += time;
    }
  }

  return step;
}
```

## 고생한 점
