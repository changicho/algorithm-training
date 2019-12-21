# 1486. 장훈이의 높은 선반

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b7Yf6ABcBBASw&categoryId=AV2b7Yf6ABcBBASw&categoryType=CODE)

난이도 : d4
정답률 : \_70%

## 설계

dfs를 이용해 합의 조합를 구한다.

이 때 합이 B를 초과했으면 MIN을 갱신하고 더이상 탐색하지 않는다.

(B 이상인 경우, 더 깊게 탐색하더라도 현재의 sum-B가 최소이므로)

## 정리

내 코드 : 16 ms

빠른 코드 : 1 ms

## 고생한 점
