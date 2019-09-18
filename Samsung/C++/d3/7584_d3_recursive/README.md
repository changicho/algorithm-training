# 7584. 자가 복제 문자열

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWpMsQfaCPMDFAQi&categoryId=AWpMsQfaCPMDFAQi&categoryType=CODE)

난이도\_d3_25%

## 정리

점화식을 발견해서 푸는 문제.

1. 4의 배수의 숫자는 0 이다. f( 4n ) = 0
2. 4의 배수가 아닌 짝수는 1 이다. f( 4n + 2 ) = 1
3. 홀수의 경우 f( 2n + 1 ) = f( n )

위 식대로 작성해서 풀면 된다.
