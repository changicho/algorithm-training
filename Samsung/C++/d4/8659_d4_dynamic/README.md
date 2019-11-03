# 8659. GCD

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW1l1s2KWn4DFARC&categoryId=AW1l1s2KWn4DFARC&categoryType=CODE)

난이도\_d4_48%

## 정리

내 코드 : 6 ms;
빠른 코드 : 5 ms;

```console
#1 2 1
#2 3 2
#3 5 3
#4 8 5
#5 13 8
#6 21 13
#7 34 21
#8 55 34
#9 89 55
#10 144 89
#11 233 144
#12 377 233
#13 610 377
#14 987 610
#15 1597 987
#16 2584 1597
#17 4181 2584
#18 6765 4181
#19 10946 6765
#20 17711 10946
```

위 결과를 보면, 다음과 같음을 알 수 있다.

i 번째 : a b
i+1 번째 : a+b a

따라서 1 번째 값만 알면 나머지는 쉽게 구할 수 있다.

### 고생한점

gcd 함수를 직점 만들고 call_count를 이용해 구하려 했으나 시간초과가 발생
규칙을 알았더라면 더 쉽게 풀 수 있었을것이다.
