# 3871. Count Commas in Range II

[링크](https://leetcode.com/problems/count-commas-in-range-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. N은 최대 10^15이다.

1,000단위 자리수별로 순회할 경우 O(5) = O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

자리수 순회에 O(1)의 공간 복잡도를 사용한다.

### 자리수 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

1,000 단위로 콤마가 1개인 갯수, 2개인 갯수 ... 5개인 갯수들을 차례로 순회한다.

```cpp
long long countCommas(long long n) {
  long long cur = 1000;
  long long limit = 1000 * 1000;
  long long count = 1;
  long long answer = 0;
  while (cur <= n) {
    answer += (min(n, limit - 1) - (cur - 1)) * count;

    cur *= 1000;
    count++;
    if (limit >= 1e15) {
      limit = 1e16;
    } else {
      limit *= 1000;
    }
  }
  return answer;
}
```

## 고생한 점
