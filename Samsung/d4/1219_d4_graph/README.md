# 1219. [S/W 문제해결 기본] 4일차 - 길찾기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14geLqABQCFAYD&categoryId=AV14geLqABQCFAYD&categoryType=CODE)

난이도 : d4
정답률 : \_81%

## 설계

### 입력

테스트케이스 쌍의 개수

(쌍의 개수 \* 2)
출발 도착

### 자료구조

각 노드가 연결되었는지 확인하기 위해 bool map[100][100] 을 이용한다.

단방향 연결이므로, 한쪽으로면 연결한다.

queue를 이용해 BFS 탐색을 수행한다.

각 노드마다 연결된 점을 탐색하고, 연결 되어 있는 점을 queue에 push한다.

만약 현재 노드가 도착점이면 탐색을 중지한다.

## 정리

내 코드 : 17 ms;
빠른 코드 : 1 ms;

## 고생한 점
