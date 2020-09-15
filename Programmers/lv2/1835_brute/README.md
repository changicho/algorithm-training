# 1835. 단체사진 찍기

[링크](https://programmers.co.kr/learn/courses/30/lessons/1835)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |    615    |

## 설계

### 시간 복잡도

인원은 총 8명이고, 1열로 나열하는 경우의 수는 8! 이다.

이는 40,320이므로 모든 경우에 대해 만족하는 경우의 수만 count 하면 된다.

### 공간 복잡도

일열로 서있는 것을 나타낼 배열을 선언한다.

배열에는 문자 한글자씩만 들어감

정답의 경우의 수도 40,320 까지이므로 int로 선언함

### 모든 경우를 만들기

재귀를 이용하거나 next_permutation을 이용해 모든 경우를 만들 수 있다.

```cpp
do {
  bool flag = true;
  for (Case cur : cases) {
    if (!flag) break;
    if (!isFine(arr, cur)) flag = false;
  }

  if (flag) answer += 1;

} while (next_permutation(arr.begin(), arr.end()));
```

### 조건 따지기

조건의 숫자는 두 인원 사이의 인원의 수이다.

단순히 두 인원의 index만으로 비교하는 경우 두 사람 사이의 수를 나타내지 않으므로

index의 차이에 1을 빼야 입력받은 조건의 숫자와 비교 할 수 있다.

먼저 배열을 순회하며 두 인원의 index를 구한 뒤 다음 조건에 따라 분기처리한다.

(이 때 index의 차이의 절대값을 이용한다)

- "=" 인 경우 : size + 1 == abs(fromIdx - toIdx) 이면 true
- ">" 인 경우 : size < abs(fromIdx - toIdx) - 1 이면 true
- "<" 인 경우 : size > abs(fromIdx - toIdx) - 1 이면 true

## 고생한 점
