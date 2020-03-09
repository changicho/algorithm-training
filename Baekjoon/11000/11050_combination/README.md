# 11050. 이항 계수 1

[링크](https://www.acmicpc.net/problem/11050)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Bronze I |     64      |

## 설계

### 이항계수(파스칼의 삼각형)

파스칼의 삼각형을 이용한다.

nCk = (n-1)C(k-1) + (n-1)Ck

```cpp
int combi(int n, int k) {
  if (k == 0 || n == k) return 1;

  // case_choose + case_not_choose
  return combi(n - 1, k - 1) + combi(n - 1, k);
}
```

### 메모이제이션

n,k쌍이 중복되는 경우가 많으므로, 시간복잡도를 줄이기 위해선 메모이제이션이 필요하다.

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  0 ms   |           |

기존의 알고리즘에서 backtracking을 사용하지 않는다면 중복되는 (n,k)쌍을 많이 호출하게 된다.

100 3 을 구하는 경우 32만번정도 재귀를 호출함

## 고생한 점