# 8568. 3으로 나눈 순열

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW1B8rJq3NUDFARC&categoryId=AW1B8rJq3NUDFARC&categoryType=CODE)

난이도\_d4\_34%

## 정리

내 코드 : 105 ms
제일 빠른 코드 : 15 ms

BFS 로 해결하는 문제가 아니였다.

주어진 배열은 문제 조건에 따라 정렬하는 문제.
정렬의 우선순위를 두어 풀었다.

1 순위 : swap 하는 두 수가 둘다 올바른 위치로 이동.
1 순위를 수행하고 나난 뒤 배열에서, 정답과 다른 요소의 갯수는 3의 배수이다!

2 순위 :
이를 쪼개 생각해보자
2 3 1 을 1 2 3 으로 만들어야 하는 경우, 2번 이동하면 된다.
2 3 1 3 1 2 의 경우, 4번 이동하면 된다.
즉 (남은 요소의 갯수 / 3) * 2 번을 더 수행하면 정답 배열로 만들 수 있다.

이를 이용해 1순위 이동 수 count + 2순위 이동 수 count = 정답
