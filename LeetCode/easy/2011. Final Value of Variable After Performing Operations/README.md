# 2011. Final Value of Variable After Performing Operations

[링크](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열 operations의 크기를 N이라 하자.

operation의 종류는 4가지이며 각 종류에 따라 연산을 수행한다.

이 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
int finalValueAfterOperations(vector<string>& operations) {
  int x = 0;

  for (string& oper : operations) {
    if (oper == "--X" || oper == "X--") {
      x--;
    } else if (oper == "++X" || oper == "X++") {
      x++;
    }
  }

  return x;
}
```

## 고생한 점
