# 8338. 계산기

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWxpQia60FgDFAWL&categoryId=AWxpQia60FgDFAWL&categoryType=CODE)

### 난이도 d3

## 정리
- 큰수

최대 값 10^9 정도
long long int형으로, 아슬하슬하게 맞추려면 unsigned int형으로 선언한다.

메모리 제한이 없으므로 long long int형으로 선언
다음 수를 곱할 때와, 더했을 때 값을 비교한 후, 더 큰값으로 갱신해 탐색하면 된다.

테스트 케이스가 많으므로 cout을 사용하면 안되고, 출력부분은 전부 printf로 처리해야한다.