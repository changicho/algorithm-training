# 1859. 백만 장자 프로젝트
[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE)

### 난이도 d2

## 정리
- 탐색

```cpp
freopen("input.txt", "r", stdin);
```
위 코드를 이용하면 input.txt의 값으로 바로 테스트 가능하다.

앞에서부터 탐색하지 말고, 뒤에서부터 탐색하면 쉽게 풀 수 있다.

맨 마지막날을 end라 하고 현재 기준 target 으로하자.
n번째 날의 값이 end보다 크다면, n+1번째부터 end까지 전부 팔면 된다.
target을 n번째로 갱신하고 탐색을 계속한다.