# 5656. [모의 SW 역량테스트] 벽돌 깨기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo)

난이도\_58%

## 정리

내 코드 : 1372 ms;
빠른 코드 : 9 ms;

구슬을 떨어뜨리는 경우는 W^4 만큼 존재하고, 이 모든 경우를 탐색하면서 블록의 남은 수가 가장 적은 경우를 찾아야한다.

각 과정을 부분으로 나눠 함수를 만들고, 호출했다.

## 고생한점

1. segmentation fault 즉 배열 index 범위 초과 에러가 발생했다. (local에선 발생 안함)
   - 직전 map을 기억하기 위해 map을 vector로 선언하고 초기화 하는 과정에서 오류 발생.
   - 각 방향별로 좌표 유효성 검사를 이동 전이 아닌 이동 후에 수행해서 오류 발생.
2. dfs에서 depth의 최대치를 생각을 잘못해서 엉뚱한 답이 도출되었다.

## 개선방안

- 애초에 설계할 때, depth가 상황별로 어떻게 될지 고민하고 구성하자.
- map을 vector로 구성할 경우 코드 실행 후 오랜 시간이 걸리므로 좋은 방법은 아닌듯 하다.
