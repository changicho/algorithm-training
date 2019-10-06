# 6190. 정곤이의 단조 증가하는 수

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWcPjEuKAFgDFAU4&categoryId=AWcPjEuKAFgDFAU4&categoryType=CODE)

난이도\_d3\_26%

## 정리

내 코드 : 241 ms
빠른 코드 : 85 ms
vector가 아닌 배열로 바꿧을 때 : 192 ms

단조 증가하는 수를 판단할 때, string 으로 풀면 시간 초과가 난다.
30,000 * 30,000 이하 이므로 long long 형태로 선언하고, % 연산을 통해 단조 증가하는 수를 판별했다.

3
1 1 1
이 경우, 모든 조합에서 한자리 수가 나오는데, 이를 단조 증가하는 수로 예외처리 하지 않아도 된다.
"어떤 k자리 수 X = d1d2…dk 가 d1 ≤ d2 ≤ … ≤ dk 를 만족하면 단조 증가하는 수이다." 에서 k>1 이란 조건이 없기 때문

vector 보다 배열로 했을 때 더 빠르다.
long long 형 보다 int 형으로 바꿧을 때 4ms 더 빠르다.
