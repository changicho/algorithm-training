# 2769. Find the Maximum Achievable Number

[링크](https://leetcode.com/problems/find-the-maximum-achievable-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N, T라 하자.

계산을 이용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

계산을 이용할 경우 별도의 공간이 필요하지 않다.

### 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(1)     |    O(1)     |

각 연산마다 num은 1증가하고 목표값은 1 감소할 때 t번을 만족하는 값을 구해야 한다.

이 때 두 값의 차이는 2 \* T이므로 이를 num에 더해 반환한다.

```cpp
int theMaximumAchievableX(int num, int t) { return num + 2 * t; }
```

## 고생한 점
