# D. A-B-C Sort

[link](https://codeforces.com/contest/1674/problem/D)

time : 30 min

## 풀이

> 변환 규칙을 찾기


입력된 배열을 [a, b, c, d] 라고 하자. 

A에서 B로 옮길 때 다음과 같은 경우의 수가 생긴다.

```text
[a, b, c, d] : []
[a, b, c] : [d]
[a, b] : [c, d] or [d, c]
[a] : [c, b, d] or [d, b, c]
[] : [c, b, a, d] or [c, a, b, d] or [d, b, a, c] or [d, a, b, c]
```

해당 상황에서 B에서 C로 옮길 때 변환되는 경우의 수는 다음과 같다.

```text
[a, b, c, d]
[b, a, c, d]
[a, b, d, c]
[b, a, d, c]
```

여기서 다음 규칙을 찾을 수 있다.

- swap i, i+1 (i is even)

배열의 길이가 홀수 인 경우를 살펴보자.

홀수의 경우 맨 마지막에 B로 이동한 수는, C로 이동할 때 제일 먼저 나오게 된다.

이후 나머지 원소에 대한 이동은 짝수 길이일 때와 동일하다.

이를 이용해 배열의 특정 구간이 내림차순이 되지 않도록 구성하기 위해 다음 연산을 수행한다.

```cpp
if (n % 2 == 0) {
  for (int i = 0; i < n; i += 2) {
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
  }
} else {
  for (int i = 1; i < n; i += 2) {
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
  }
}
```

즉 그리디하게 변경할 수 있는 구간들을 모두 오름차순으로 변경한다.

이후 특정 구간이 내림차순인지 비교하고 반환한다.