# 1509. 팰린드롬 분할

[링크](https://www.acmicpc.net/problem/1509)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   46.688    |       2       |

## 설계

### 시간 복잡도

문장의 길이 N은 최대 2,500 까지이다.

매 경우마다 팰린드롬인지 검사 하는데 들어가는 시간 복잡도는 O(N) 이다.

문장을 가장 큰 팰린드롬으로 이루어진 덩어리로 분리하는 경우 (분할의 개수의 최솟값) 모든 경우를 탐색할 때 시간 복잡도는 2^N 이며 이는 제한시간 2초 내에 불가능하다.

각 경우마다 팰린드롬인지 검사할 경우도 제한시간 내에 불가능하므로, 다음 경우에 대해서 메모이제이션을 수행한다.

- 팰린드롬인지 여부
- 가장 큰 덩어리로 나눈 개수

이 경우 시간 복잡도는 O(N^2) 이며 제한시간 내에 충분하다.

### 공간 복잡도

문자열의 길이는 최대 2,500 까지이다.

아무리 큰 덩어리로 나누더라도 정답의 최대값은 2,500 이므로 int형으로 선언한다.

### 팰린드롬인지 여부

팰린드롬의 경우 다음 규칙을 따른다.

from ~ to 까지의 문자열이 팰린드롬인지 확인하는 방법은 다음과 같다.

- (from + 1) ~ (to - 1) 까지의 문자열이 팰린드롬인지 여부
- from, to 번째의 문자들이 같은지 여부

두 경우가 모두 충족할 경우 from ~ to 까지의 문자열은 팰린드롬이다.

위 식을 이용해 일반식을 다음과 같이 구할 수 있다.

```cpp
isPalindrome[from][to] = (line[from] == line[to]) && isPalindrome[from + 1][to -1]
```

isPalindrome의 초기값은 다음과 같다.

- 길이가 1인 문자열은 모두 팰린드롬이다.
- 길이가 2인 문자열이 같은경우 팰린드롬이다.

여기서 길이가 2인 문자열 까지 확인하는 이유는 길이가 2인 경우 (from + 1)이 (to - 1)보다 커지기 때문이다.

따라서 다음과 같이 초기값을 세팅한다.

```cpp
isPalindrome[0][0] = true;
for (int i = 1; i < N; i++) {
  isPalindrome[i][i] = true;
  isPalindrome[i - 1][i] = array[i - 1] == array[i];
}
```

이후 검사할 문자열의 길이를 증가시키며 isPalindrome를 갱신한다.

```cpp
for (int length = 2; length < N; length += 1) {
  for (int from = 0; from < N - length; from += 1) {
    int to = from + length;
    isPalindrome[from][to] = array[from] == array[to] && isPalindrome[from + 1][to - 1];
  }
}
```

### 분할의 개수의 최솟값

최솟값 배열을 다음과 같이 정의한다.

```cpp
count[index] // index번째 까지 길이를 팰린드롬 덩어리로 나눴을 때 최소값
```

배열의 초기값은 다음과 같다.

```cpp
count[0] = 1; // 첫 문자는 무조건 팰린드롬
```

현재 index를 구하는 일반 식은 다음과 같다.

```cpp
count[index] = count[index - 1] + 1;  // 직전 경우에서 현재 문자를 팰린드롬으로 하여 더하는 경우

// 현재 문자열까지 팰린드롬인경우 전부 팰린드롬으로 나눌 수 있음
if (isPalindrome[0][index]) {
  count[index] = 1;
}

// index를 순회하면서 더 작은 경우의 수가 있는지 탐색
// cur ~ index까지 팰린드롬인 경우
// 0 ~ (cur - 1) / cur ~ index 로 분할해서 생각할 수 있음;
for (int cur = 1; cur <= index; cur++) {
  if (isPalindrome[cur][index]) {
    count[index] = min(count[index], count[cur - 1] + 1);
  }
}
```

다음 방법으로 순회해 count배열을 갱신한다.

```cpp
for (int index = 1; index < N; index++) {
  count[index] = count[index - 1] + 1;

  if (isPalindrome[0][index]) {
    count[index] = 1;
  }

  for (int cur = 1; cur <= index; cur++) {
    if (isPalindrome[cur][index]) {
      count[index] = min(count[index], count[cur - 1] + 1);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      36      |       0        |

## 고생한 점
