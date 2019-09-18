# 7532. 세영이의 SEM력 연도

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWooplJ60l8DFARx)

난이도\_d3_62%

## 정리

내 코드 16ms
제일 빠른 코드 c++ 7ms
시간 개선한 내 코드 11ms

가능한 경우를 전부 비교해보는 문제.
하지만 숫자를 하나하나 증가시키면서 비교하는 것은 시간초과가 난다 (1초 초과)

S, E, M 은 각각
365의 배수 + S
24의 배수 + E
29의 배수 + M
을 의미한다.

여기서 S의 한계치인 365가 제일 큰 숫자이므로, day = S 로 설정하고 365를 계속 더해나간다.
더할 때마다 정답에 부합하는지 비교하면 끝

## 시간 개선

cin, cout 이 아닌 scanf, printf 를 사용하면 오히려 시간이 늘어난다.

마의 10ms 의 벽을 깨기가 너무 어렵다.
