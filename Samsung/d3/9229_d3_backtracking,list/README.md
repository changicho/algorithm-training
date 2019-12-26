# 9229. 한빈이와 Spot Mart

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW8Wj7cqbY0DFAXN&categoryId=AW8Wj7cqbY0DFAXN&categoryType=CODE)

난이도 : d3
정답률 : \_36%

## 설계

N : 1000

M : 2,000,000

과자봉지 무게 : 1,000,000

모든 경우를 탐색할 경우 시간 복잡도는 1000 X 1000 X 273 이다.

이는 약 2억정도이므로 backtracking을 수행해야 한다.

### backtracking

1. M보다 큰 값이 입력되는 경우 무시한다.
2. 오름차순으로 정렬 후 탐색한다.

여기서 2번의 경우 오름차순으로 정렬 후 탐색을 시작할 경우에, 두 과자봉지의 합이 M을 초과하기 시작한 경우 그 이후의 모든 방법이 M을 초과하므로 무의미한 탐색을 줄일 수 있다.

## 정리

내 코드 : 49 ms;

빠른 코드 : 16 ms;

## 고생한 점

처음 코드에서 runtime error 가 발생했는데, 이유를 알 수가 없다.

변경한점

1. 변수명 MIN 삭제
2. 사용하지 않는 string include 제외
