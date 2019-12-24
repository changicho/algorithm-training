# 1244. [S/W 문제해결 응용] 2일차 - 최대 상금

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE)

난이도 : d4
정답률 : \_43%

## 설계

dfs를 이용해 변경 가능한 경우를 탐색한다.

이 때 backtracking을 사용하지 않는 경우 시간 초과가 발생한다.

큰 수를 만드는 경우 앞자리부터 높은 자리 수를 넣으면 된다.

1. 현재 자리 수 이상의 수를 발견한 경우 swap을 수행하고 dfs를 호출한다.
2. dfs의 depth가 C (변경 횟수)인 경우 answer를 갱신하고 탐색을 중지한다.

### 예시로 주어진 49 <-> 94

예시로 주어진 49 <-> 94의 경우 는 고려하지 않아도 된다.

주어진 숫자는 6자리이기 때문에 원위치 시키는 경우는 존재하지 않기 때문이다.

## 정리

내 코드 : 10 ms;
빠른 코드 : 1 ms;

## 고생한 점
