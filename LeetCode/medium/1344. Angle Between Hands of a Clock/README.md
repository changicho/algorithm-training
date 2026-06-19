# 1344. Angle Between Hands of a Clock

[링크](https://leetcode.com/problems/angle-between-hands-of-a-clock/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

수학을 사용해 비율을 구할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

수학을 사용해 비율을 구하는데 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

시침, 분침이 12시 00분 기준으로 얼마나 이동했는지 퍼센트를 구한다.

이후 두 퍼센트의 차이 중 작은 값을 이용해 정답을 갱신한다.

```cpp
double angleClock(int hour, int minutes) {
  double mV = (minutes / 60.0) * 100.0;
  double hV = (hour % 12) / 12.0 * 100.0 + mV / 12.0;

  double val = abs(mV - hV);
  val = min(val, 100.0 - val);

  return val * 360 / 100.0;
}
```

## 고생한 점
