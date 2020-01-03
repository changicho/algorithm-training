# 1215. [S/W 문제해결 기본] 3일차 - 회문1

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14QpAaAAwCFAYi&categoryId=AV14QpAaAAwCFAYi&categoryType=CODE)

난이도 : d3
정답률 : \_84%

## 설계

가로로 검색 한번, 세로로 검색 한번을 수행함.

탐색시 배열의 크기를 초과할 경우 예외처리.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  6 ms   |   1 ms    |

## 고생한 점

배열의 크기를 초과하는 경우를 막기 위해 index를 조정했다.

이 때 00001111 이 부분을 탐색하는 것을 빠뜨림.
