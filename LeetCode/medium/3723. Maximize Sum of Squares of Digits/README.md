# 3723. Maximize Sum of Squares of Digits

[링크](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

가장 유리한 대로 큰수를 우선적으로 선택해 정답을 생성할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 탐욕 (그리디)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

문제 조건에 따라 각 자리수의 제곱을 더해야한다.

이를 가장 유리하게 하기 위해선 매번 가능한 가장 큰 값을 현재 자리수로 선택하는 편이 유리하다.

따라서 남은 값 중에서 0~9까지 중 가장 큰 값을 자리수로 선택해 채워나간다.

이때 모든 자리를 9로 채워도 정답을 만족하지 못하거나 아무 자리수도 채워넣을 수 없는 경우 불가능하다.

```cpp
string maxSumOfSquares(int num, int sum) {
  string answer(num, '0');
  if ((sum == 0) || (num * 9 < sum)) return "";

  for (int i = 0; i < num; i++) {
    int d = min(9, sum);

    answer[i] = (d + '0');
    sum -= d;
  }

  if (sum > 0) return "";
  return answer;
}
```

## 고생한 점
