# 1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱

난이도 : d3

## 설계

```cpp
int req(int A, int B) {
  if (B == 1) {
    return A;
  }
  return A * req(A, B - 1);
}
```

## 정리

## 고생한 점
