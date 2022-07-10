# 2321. Maximum Score Of Spliced Array

[링크](https://leetcode.com/problems/maximum-score-of-spliced-array/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

n1, n2의 크기를 N이라 하자.

카데인 알고리즘을 이용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

카데인 알고리즘을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 카데인 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     202      |    O(N)     |    O(1)     |

각 배열의 총 합에서, 각 두 배열의 차이의 부분합중 가장 큰 값을 더한 값중 최대값을 찾는다.

이는 A에서 일부분을 B로 치환한것이 답이라고 할 때, 결국 A의 총합에서 해당 부분만큼의 차이값 (해당 부분은 B가 더 크므로)을 더한 값이 답이 되기 때문이다.

최대 부분 합은 카데인 알고리즘으로 구한다.

카데인 알고리즘은 `각각의 최대 부분합은 이전 최대 부분합이 반영된 결과값` 이라는 특성을 이용해, 최대 부분합을 O(N)의 시간 복잡도로 구하는 알고리즘이다.

따라서 카데인 알고리즘을 이용해 배열 A와 B의 차이에 대한 최대 부분합을 구하고 이를 배열 A에 더할 경우, A를 유지하고 일부분을 B로 치환했을 때의 최대 합을 구할 수 있다.

이를 순서를 바꿔 B, A에 대해서도 수행해준다.

위 두 연산의 결과중 최대값이 정답이다.

```cpp
int kadane(vector<int>& n1, vector<int>& n2) {
  int size = n1.size();
  int sum = 0, res = 0;

  for (int i = 0; i < size; i++) {
    sum = max(n2[i] - n1[i], sum + n2[i] - n1[i]);
    res = max(res, sum);
  }

  return res;
}

int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
  int sum1 = accumulate(begin(n1), end(n1), 0);
  int sum2 = accumulate(begin(n2), end(n2), 0);

  return max(sum1 + kadane(n1, n2), sum2 + kadane(n2, n1));
}
```

## 고생한 점
