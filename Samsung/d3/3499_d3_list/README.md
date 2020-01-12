# 3499. 퍼펙트 셔플

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWGsRbk6AQIDFAVW&categoryId=AWGsRbk6AQIDFAVW&categoryType=CODE)

난이도 : d3
정답률 : \_56%

## 설계

짝수인 경우 0 ~ (N/2 -1) 까지와 N/2 ~ N-1 까지로 나눈다.

홀수인 경우 0 ~ ((N+1)/2 -1) 까지와 (N+1)/2 ~ N-1 까지로 나눈다.

0부터 시작하는 index와 center부터 시작하는 index를 만들어 교차 출력한다.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  9 ms   |   2 ms    |

## 고생한 점
