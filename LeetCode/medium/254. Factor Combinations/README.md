# 254. Factor Combinations

[링크](https://leetcode.com/problems/factor-combinations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N을 약수로 나눴을 때 가질 수 있는 1을 제외한 약수의 최대 개수는 log_2(N) 이하이다.

(인수 중 1을 제외한 가장 작은 값은 2 이므로)

이 때 X를 N의 약수라 했을 때 X, N/X 두 수는 모두 N의 약수가 된다.

따라서 각 경우마다 재귀호출을 이용해 값을 탐색할 때, sqrt(N)만큼 탐색을 진행한다.

이는 최대 call stack에 sqrt(N)번 만큼 쌓일 수 있다.

따라서 시간 복잡도는 O(sqrt(N) \* sqrt(N)) 이므로 O(N)이다.

### 공간 복잡도

call stack에 최대 sqrt(N)까지 쌓일 수 있다.

정답의 경우 조합이 최악의 경우 O(log_2(N))의 공간을 차지할 수 있다.

이 경우가 최대 sqrt(N)번 나올 수 있으므로 공간 복잡도는 O(log_2(N) \* sqrt(N))이다.

### backtracking

| 내 코드 (ms) | 시간 복잡도 |      공간 복잡도       |
| :----------: | :---------: | :--------------------: |
|      8       |    O(N)     | O(log_2(N) \* sqrt(N)) |

재귀 호출을 이용해 탐색을 진행한다.

이 때 X가 N의 약수인 경우 정답 배열에 X와 N/X을 삽입한다.

이 때 N/X가 정답 배열에 들어가는 경우와, N/X에 대해서 약수의 쌍을 구하는 두 경우 모두 탐색을 진행해 중복된 탐색을 피할 수 있다.

```cpp
vector<vector<int>> answer;

void recursive(vector<int> &array, int n) {
  int left = array.empty() ? 2 : array.back();
  int right = sqrt(n);

  for (int num = left; num <= right; num++) {
    if (n % num == 0) {
      array.emplace_back(num);
      array.emplace_back(n / num);
      // 현재 경우 정답에 추가
      answer.emplace_back(array);
      // n / num에 대한 조합을 재귀호출로 탐색
      array.pop_back();
      recursive(array, n / num);
      array.pop_back();
    }
  }
}

vector<vector<int>> getFactors(int n) {
  vector<int> array;
  recursive(array, n);
  return answer;
}
```

## 고생한 점
