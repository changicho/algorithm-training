# 2303. Calculate Amount Paid in Taxes

[링크](https://leetcode.com/problems/calculate-amount-paid-in-taxes/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

brackets의 크기를 N이라 하자.

각 bracket을 순회하며 income과 비교하고 초과분에 대해서만 세금을 계산해 더한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회후 tax를 계산할 때 별도의 배열을 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

현재 상한과 이전 상한의 차이에 현재 세율을 곱해 현재 세금을 구한다.

이 때 현재 상한이 income보다 큰 경우 수입보다 더 세금을 낼 수 없으므로 수입으로 바꿔 계산한다.

이 값들을 누적한다.

```cpp
double calculateTax(vector<vector<int>>& brackets, int income) {
  int size = brackets.size();

  double tax = 0, before = 0;
  for (int i = 0; i < size; i++) {
    double curTax =
        (min(brackets[i][0], income) - before) * brackets[i][1] / 100.0;

    tax += max(0.0, curTax);
    before = brackets[i][0];
  }

  return tax;
}
```

## 고생한 점
