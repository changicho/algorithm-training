# 10872. 팩토리얼

[링크](https://www.acmicpc.net/problem/10872)

정답률 : \_55%

## 설계

```cpp
factorial(int n){
  if(n<=1){
    return 1;
  }
  return n * factorial(n-1);
}
```

0! = 1 인 것에 유의.

## 정리

내 코드 : 0 ms;

## 고생한 점

0! = 1이다.
