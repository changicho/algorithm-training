# 7964. 부먹왕국의 차원 관문

[!문제링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWuSgKpqmooDFASy&categoryId=AWuSgKpqmooDFASy&categoryType=CODE)

난이도 d3

## 정리 내용

- 탐욕 알고리즘

지금 이 순간 당장 최적인 답을 선택하여 적합한 결과를 도출해 풀었다.

시작과 끝 마을에는 차원문이 존재하므로, N+2 크기의 배열을 만들고 시작점과 끝점에 1을 설정해주었다.

0번째 index 부터 탐색을 시작한다.
n번째 index 일 때, n+1 부터 n+D 번째 까지 게이트가 이미 존재하면 그곳으로 이동.
없으면 도달 가능한 가장 먼 위치에 차원문을 설치.

위를 반복해 풀었다.

## 코딩상의 주요점

cin 을 이용해 boolean 값을 읽을 수 없는 에러가 발생했다. gcc에서는 불가능한듯 하다.
좌표 정보에 들어가는 값이 0, 1 밖에 없어서 boolean 형을 사용하면 메모리를 많이 아낄 수 있을텐데...
일단 int 형으로 풀어도 합격점이다.

bool : 1 byte, int : 4 byte

while 문을 돌릴 때 조건 예외 체크를 잘 하자.
특히나 범위 내에 차원문이 존재할 때와 존재하지 않을 때를 flag 로 구분한 경우, flag 를 초기화 하는 부분 잊지 않도록!

vector 등에서 유효하지 않은 index로 접근하면 segmentation error 가 발생한다.
