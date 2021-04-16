# 29. Divide Two Integers

[링크](https://leetcode.com/problems/divide-two-integers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

dividend, divisor는 모두 int형 범위이다.

최악의 경우 시간 복잡도는 2^32 이므로 시간을 최적화 해야 한다.

분할 정복을 경우 시간 복잡도는 O(log_2(N)) 이며 최악의 경우 32이므로 제한시간 내에 충분하다.

### 공간 복잡도

overflow를 해결하기 위해 long long 을 사용할 수 있다.

이 때 공간 복잡도는 O(1) 이다.

### 분할 정복

divisor를 배수로 증가시키며 몫이 0인 경우를 탐색한다.

현재 divisor의 두배로 나눌 때 몫이 0인 경우 dividend에서 divisor만큼 빼고, 나머지에 대해서 최초의 divisor로 반복한다.

만약 현재 divisor의 두배로 나눌 때 몫이 1 이상인 경우 divisor를 두배로 증가시키고 탐색을 이어나간다.

```cpp
// 반복문을 이용한 풀이
int divide(int dividend, int divisor) {
  bool isMinus = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? false : true;
  long long answer = 0;
  long long de = abs((long long)dividend);
  long long ds = abs((long long)divisor);

  while (de >= ds) {
    long long div = ds;
    long long count = 1;
    while ((div * 2) <= de) {
      div *= 2;
      count *= 2;
    }
    answer += count;
    de -= div;
  }

  if (isMinus) answer *= -1;
  return answer > INT_MAX ? INT_MAX : answer;
}
```

```cpp
// 재귀호출을 이용한 풀이
long long answer = 0;

int divide(int dividend, int divisor) {
  bool isMinus = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? false : true;
  long long de = abs((long long)dividend);
  long long ds = abs((long long)divisor);

  recursive(de, ds, 1, ds);

  if (isMinus) answer *= -1;
  if (answer > 2147483647) answer = 2147483647;

  return answer;
}

void recursive(long long num, long long div, long long count, long long divisor) {
  if (num <= 0) return;
  if (num < div) return;
  if (num > div * 2) {
    recursive(num, div * 2, count * 2, divisor);
    return;
  }

  answer += count;

  recursive(num - div, divisor, 1, divisor);
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
