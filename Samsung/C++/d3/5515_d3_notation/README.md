# 5515. 2016년 요일 맞추기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWOwecaFrIDFAV4&categoryId=AWWOwecaFrIDFAV4&categoryType=CODE)

난이도\_d3\_66%

## 정리

내 코드 : 6 ms
빠른 코드 : 1 ms

1월 부터 12월 까지 날짜의 수 {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

M월 D일 이면, M-1번째 까지의 일 수를 전부 더하고 D를 더한 날짜가 금요일로부터 지난 날이다.
금요일 : 3 이므로
(3 + days) % 7 로 구함

1. 각 월별 날짜의 수를 잘못 생각해서 오류
2. % 7 연산 후 3을 더하면 생기는 오류
3. M-1 번째 까지 더하는 데에서 생기는 오류
