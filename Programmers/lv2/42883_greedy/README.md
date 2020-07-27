# 42883. 큰 수 만들기

[링크](https://programmers.co.kr/learn/courses/30/lessons/42883)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   1496   |

## 설계

### 시간 복잡도

완전 탐색으로 풀 경우 2^1,000,000 번 탐색해야 하므로 제한 시간 내에 불가능하다.

N^2의 방법으로도 불가능 하므로, 그리디 알고리즘을 이용해 접근한다.

### 공간 복잡도

1,000,000자리 수 이므로 string으로 선언한다.

### 그리디 알고리즘

N-K 길이의 숫자를 생성하는 문제로 변환해 생각하자.

N-K 길이의 숫자의 index와 문자를 탐색하는 start를 따로 둔다.

이때 각 자리수를 찾을 때, 최대 k번 까지 뒤로 탐색하며 그 중 가장 큰 숫자를 추가한다.

이 떄 추가한 숫자의 다음 위치로 시작점을 이동해야한다.

```cpp
for (int index = 0; index < numSize; index++) {
  char maxValue = number[start];
  int maxIndex = start;

  for (int i = start; i <= k + index; i++) {
    if (maxValue < number[i]) {
      maxValue = number[i];
      maxIndex = i;
    }
  }
  start = maxIndex + 1;
  answer += maxValue;
}
```

## 고생한 점
