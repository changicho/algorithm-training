# 9088. 다이아몬드

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW7Oktj6WMQDFAWY&categoryId=AW7Oktj6WMQDFAWY&categoryType=CODE)

난이도 : d4
정답률 : \_41%

## 설계

### 자료구조

다이아몬드 무게의 범위가 1 ~ 10,000 이므로 10001 크기의 배열을 선언한다.

### 알고리즘

다이아몬드 무게 입력시 무게를 index로 하는 배열의 count를 증가시킨다.

배열을 순회하며 현재 inex ~ 현재 inex + K 까지의 수를 count하며 max를 갱신한다.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  29 ms  |   6 ms    |

## 고생한 점

문제의 이해가 어려웠다.

처음엔 다이아몬드 쌍을 구하는 줄 알고, 정답이 모두 짝수로 나오는 경우로 생각함.

그것이 아닌 묶음이므로 한정된 범위 내의 다이아몬드의 최대 갯수를 구하는 문제였다.
