# 12945. 피보나치 수

[링크](https://programmers.co.kr/learn/courses/30/lessons/12945)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   7423   |

## 설계

### 시간 복잡도

n은 최대 100000 까지이다.

피보나치 수를 동적계획법으로 풀지 않을 경우 시간복잡도는 매우 크므로 제한시간 내에 풀이가 불가능하다.

따라서 메모이제이션을 이용한다.

### 공간 복잡도

피보나치 수는 1234567로 나눈 나머지 이므로 int형으로 충분하다.

### 피보나치수열

```cpp
int fibo(int n) {
  if (n < 1) {
    return 0;
  }
  if (n == 1) {
    return n;
  }

  if (memo[n] != 0) {
    return memo[n];
  }

  return memo[n] = (fibo(n - 1) + fibo(n - 2)) % DIV;
}
```

## 고생한 점
