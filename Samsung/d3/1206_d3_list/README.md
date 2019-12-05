# 1206. [S/W 문제해결 기본] 1일차 - View

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE)

난이도 : d3
정답률 : \_70%

## 설계

입력 N <= 1000

최대 높이는 255

맨 왼쪽과 오른쪽 2칸은 0으로 이루어져있음.

2 ~ N-2 까지 순회를 한다.

i번째일때 :

i-2, i-1, i+1, i+2 전부 현재 높이보다 낮은지 판단.

낮으면 count를 증가시키고 현재 높이를 낮춘다.

## 정리

내 코드 : 8 ms;
빠른 코드 : 2 ms;
개선한 코드 : 7 ms;

vector 대신 배열을 사용해도 큰 시간단축이 이루어지지 않았다.

한층한층 비교해가면서 count 하지 않고, 인접한 4개의 칸에서 가장 큰 수와 현재 층의 차이만큼 count 시킬수도 있다.

이 방법으로도 큰 개선이 이루어지지는 않았다.

## 고생한 점
