# 7227. 사랑의 카운슬러

[링크](https://swexpertacademy.com/main/main.do)

난이도_d3_45%

## 정리

내 코드 : 352ms
가장 빠른 코드 : 37ms

C++ 구조체 생성자
[구조체 생성자 초기화 방법](https://dreamaz.tistory.com/437)
[std::vector - push_back](https://shaeod.tistory.com/574)

원래는 d4였던 문제 (1494. 사랑의 카운슬러)

ex) sample에서
6 0, -7 2 < 움직이는 지렁이
3 3, -4 -1

순서대로 이동 거리는 3 -3, -3 3
교차한 이동 거리는 10 1, -10 -1
순서에 상관이 없이 총 이동거리의 합은 같다.

따라서 움직이는 지렁이 / 안 움직이는 지렁이로 나누어서 계산하면 됨

next_permutation을 이용한 방법은 전부 시간초과가 난다. < next_permutation의 문제가 아니였다
vector을 사용하면 전부 시간초과가 난다! resize에서 문제가 생기는듯 하다.

DFS 방법도 조합을 생성하는 경우이므로 next_permutation과 같은데도 말이다.
