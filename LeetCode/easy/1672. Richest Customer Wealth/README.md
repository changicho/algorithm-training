# 1672. Richest Customer Wealth

[링크](https://leetcode.com/problems/richest-customer-wealth/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

accounts의 행의 개수를 R, 열의 개수를 C라고 하자.

각 행을 순회하며 열에 해당하는 값을 더하고 이 중 최대값을 찾아야 한다.

모든 원소를 순회해야 하므로 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 원소를 행별로 순회하는 경우 별도의 공간 복잡도를 사용하지 않는다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(R \* C)  |    O(1)     |

각 행별로 순회하며 행의 모든 값을 더한 후 정답을 갱신한다.

```cpp
int maximumWealth(vector<vector<int>> &accounts) {
  int answer = 0;

  for (vector<int> &account : accounts) {
    int cur = 0;
    for (int &w : account) {
      cur += w;
    }
    answer = max(answer, cur);
  }

  return answer;
}
```

## 고생한 점
