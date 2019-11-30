# 10870. 피보나치 수 5

[링크](https://www.acmicpc.net/problem/10870)

정답률 : \_71%

## 설계

```cpp
int fibo(int n){
  if(n <= 0){
    return 0;
  }
  if(n <= 2){
    return 1;
  }
  return fibo(n-1)+fibo(n-2);
}
```

피보나치 수열
0일 때 0
1일 때 1
2일 때 1

n번째 일 떄 f(n-1)+f(n-2)

## 정리

내 코드 : 0 ms;

## 고생한 점

1번째와 2번째 일때 1이다.
