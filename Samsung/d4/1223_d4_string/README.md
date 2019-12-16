# 1223. [S/W 문제해결 기본] 6일차 - 계산기2

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14nnAaAFACFAYD&categoryId=AV14nnAaAFACFAYD&categoryType=CODE)

난이도 : d4
정답률 : \_87%

## 설계

직전까지의 계산 결과를 저장하는 temp = 1를 선언한다.

입력이 +일 경우 answer += temp를 수행, temp = 1로 초기화

입력이 \*일 경우 무시

temp \*= 현재 숫자

이 방식때로 구현한다.

덧셈이 나올 때까지 숫자들을 계속 곱하고, 덧셈이 나오면 더한다.

## 정리

내 코드 : 5 ms
빠른 코드 : 1 ms

## 고생한 점
