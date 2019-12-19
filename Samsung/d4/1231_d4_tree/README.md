# 1231. [S/W 문제해결 기본] 9일차 - 중위순회

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE)

난이도 : d4
정답률 : \_80%

## 설계

### 제약조건

node의 최대 수 = 100

### 자료구조

node 구조체를 만든다.

value, left_index, right_index를 가진다.

입력 받는 tree들을 생성하기 위해 배열을 생성한다.

배열의 index 0은 비워두고, 탐색 시 1번부터 탐색한다.

node의 left, value, right index를 탐색한다.

### 노드의 구조 읽기

노드의 구조가 한 줄에 전부 입력된다.

이 중 자식이 있는경우와 없는 경우를 판단하기 위해 index를 이용한다.

i \* 2 가 N 이하인 경우 left를 가지며,

i \* 2 + 1 가 N 이하인 경우 right를 갖는다.

## 정리

내 코드 : 6 ms;

빠른 코드 : 1 ms;

## 고생한 점

한 줄에 노드의 정보가 모두 입력되는 것을 처리하는 부분
