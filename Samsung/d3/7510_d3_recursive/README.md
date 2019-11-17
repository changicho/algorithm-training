# 7510. 상원이의 연속 합

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWoEzJFa2A4DFARq&categoryId=AWoEzJFa2A4DFARq&categoryType=CODE)

난이도\_d3_62%

## 정리

처음 코드 : 63ms
제일 빠른 코드 : 5ms
알고리즘 개선한 코드 : 6ms

### 첫번째 알고리즘

N이 홀수면

index 1부터 N/2+1 까지 순회돌면서 (index는 2씩 증가)
N%index == 0 이면 가능
그리고 (N-1)%2 == 0 이면 가능

### 두번쨰 알고리즘

N = x + (x+1) + (x+2) + ... + (x+y)
= (y+1)x + y(y+1)/2
위 일반식을 이용

x = (2N-y^2-y) / (2y+2)
이 식을 도출할 수 있다.

여기서 y값을 증가시켜보면서 x가 정수로 나오는지 판단하면 된다.
x가 정수인지 판단은 분자 % 분모 == 0인지 확인하면 됨.
또한 분자 값이 음수가 나올 때 부터는 y는 절대 답이 될 수 없음.
