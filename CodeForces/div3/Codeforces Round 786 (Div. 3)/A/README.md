# A. Number Transformation

[링크](https://codeforces.com/contest/1674/problem/A)

| 난이도 |
| :----: |
|  *800  |

## 설계

### 시간 복잡도

입력받은 x, y에 대해서 만족하는 a, b를 모두 찾아 구할 경우 모든 경우를 살펴봐야 하므로 제한시간 내에 불가능하다.

따라서 약수를 이용해 약수를 만들 수 있는 a, b를 반환한다. 이는 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

약수를 찾아 a, b를 구할 경우 별도의 공간 복잡도를 사용하지 않는다.

### 약수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(1)     |    O(1)     |

x를 y로 만들기 위한 정수 두 쌍을 찾아야한다.

정수 쌍이 존재하기 위해선 y를 x로 나눈 나머지가 0이여야 한다. (x가 y의 약수여야함)

또한 분수, 음의 정수는 불가능하므로 y는 x이상이여야 한다.

정답은 어느것이여도 상관없으므로 1과 y/x 인 값을 한번 곱한 값의 쌍을 정답으로 반환한다.

```cpp
struct Response {
  int a, b;
};

Response solution(int x, int y) {
  if (x > y) return {0, 0};
  if (y % x != 0) return {0, 0};

  int target = y / x;
  int val = 1;

  return {1, target};
}
```

## 입출력

### input

```text
3
3 75
100 100
42 13
```

### output

```text
2 5
3 1
0 0
```

## 고생한 점