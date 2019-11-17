# 7193. 승현이의 수학공부

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWksRkI6AR0DFAVE)

난이도\_d3_29%

## 정리

내 코드 : 1,297 ms
제일 빠른 코드 : 391 ms

페르마의 소정리를 이용
a^p % p = a 이다.
2^3 % 3 = 2 이므로 성립.

9진법 수 234는 2 X 9^2 + 3 X 9^1 + 4 X 9^0 이다.
이때 %8 연산을 수행한 결과는
2 X 9^2 % 8 +
3 X 9^1 % 8 +
4 X 9^0 % 8
로 나타낼 수 있다.

거기에 3X9 % 8 = 3%8 X 9%8 = 3임을 이용한다.
각 자리수 별로 연산을 하고 더하면 된다!
