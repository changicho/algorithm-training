# 4053. Minimum Operations to Make Every Element Palindromic

[링크](https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대 10^9까지의 팰린드롬(회문)의 갯수를 M이라 하자.

(M = 10^5 + 10^4 이하임이 보장됨)

미리 회문의 경우를 모두 구하고 정렬하는데 O(M \* log_2(M))의 시간 복잡도를 사용한다.

이후 각 배열의 원소를 순회하며 이분 탐색으로 순회하는데 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

회문을 저장 + 정렬하는데 O(M)의 공간 복잡도를 사용한다.

### DFS & 이분 탐색

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      61      | O(M \* log_2(M) + N \* log_2(M)) |    O(M)     |

DFS를 이용해 가능한 회문 세트들을 구한다. 여기서 짝, 홀수를 구분해 저장한다.

이후 회문들을 정렬해 이후 이분탐색에서 사용한다.

이후 각 값마다 순회하며 현재 값과 가장 가까이 있는 회문숫자를 탐색 후 최소 변경횟수를 구한다.

```cpp
vector<long long> targets[2];

void dfs(long long num, int length) {
  if (length >= 10) return;

  int digit = (num > 0 ? log10(num) : 0) + 1;
  if (digit == length) {
    targets[num % 2].push_back(num);
  }

  for (int i = 0; i <= 9; i++) {
    long long next = i * pow(10, length + 1) + num * 10 + i;
    dfs(next, length + 2);
  }
};

int init = []() {
  dfs(0, 0);
  for (int i = 0; i <= 9; i++) {
    dfs(i, 1);
  }

  sort(targets[0].begin(), targets[0].end());
  sort(targets[1].begin(), targets[1].end());
  return 0;
}();

long long minOperations(vector<int>& nums) {
  int size = nums.size();
  long long answer = 0;

  for (int& num : nums) {
    int d = num % 2;
    int upperI = upper_bound(targets[d].begin(), targets[d].end(), num) -
                  targets[d].begin();

    long long lower = targets[d][upperI - 1];
    long long upper = targets[d][upperI];

    long long diff = min(abs(lower - num) / 2, abs(upper - num) / 2);
    answer += diff;
  }

  return answer;
}
```

## 고생한 점

회문 세트는 재사용해야하므로 초기에 한번만 실행 후 저장한다.
