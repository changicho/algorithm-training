# 1393. 음하철도 구구팔

[링크](https://www.acmicpc.net/problem/1393)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   28.926    |

## 설계

### 시간 복잡도

정답은 정수인 좌표 이다.

최악의 경우 (-100, -100)에서 (100, 100)으로 (1,1)로 가는 경우를 생각해보자.

이 때 정답은 (100, 100) 이며 이는 200초 이후의 값이다.

따라서 최악의 경우의 시간 복잡도도 200 이하임을 알 수 있다.

### 공간 복잡도

모든 수는 절대값 100 이하의 정수이다 따라서 int형으로 선언한다.

이 때 -100 과 같은 음수와 0도 가능함에 주의한다

최악의 경우에도 좌표의 합산은 20100 이내이므로, int형을 넘지 않는다.

### 최대 공약수

좌표가 이동을 최대 공약수를 이용해 압축 해야 한다.

이는 정답이 정수이기 때문이며, 1초에 (2, 4) 로 이동하는 경우 0.5초 동안 (1, 2)로 이동하는 것과 같기 때문이다.

정답은 좌표만 출력하므로 1초 이내에 정수좌표로 이동하는 경우도 고려해야한다.

gcd는 다음과 같이 구현한다.

```cpp
int getGcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;

  return getGcd(b, a % b);
}
```

이 때 a,b가 음수가 들어올 수 있으므로, getGcd를 호출할 때 음수를 양수로 치환해준다.

### 좌표 구하기

최악의 경우도 200번 반복하면 되고, 입력받은 이동하는 좌표를 gcd를 이용해 나눠준다.

이후 200번 반복해가며 좌표간의 거리가 최소일 때 정답을 갱신한다.

최악의 경우도 int형의 범위를 넘지 않는다.

```cpp
int gcd = getGcd(abs(diff.x), abs(diff.y));

if (gcd != 0) {
  diff.x /= gcd;
  diff.y /= gcd;
}

int length = getLength(destination, start);

for (int i = 0; i < 200; i++) {
  start.x += diff.x;
  start.y += diff.y;

  int newLength = getLength(destination, start);

  if (newLength < length) {
    length = newLength;
    answer = start;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
