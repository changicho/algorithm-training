# 1088. Confusing Number II

[링크](https://leetcode.com/problems/confusing-number-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

confusing number를 구성할 수 있는 원소는 0,1,6,8,9 5가지이다.

해당 5가지 경우의 수에 대해서 N까지 탐색을 진행한다.

이 때 각 경우마다 confusing number만 정답으로 count해야 한다.

이 때 confusing number인지 판단하는 데 O(log_10(N))의 시간 복잡도를 사용한다.

각 경우마다 5가지 수를 사용하므로, 이를 log_10(N)번 탐색한다.

따라서 경우를 탐색하는데 시간 복잡도는 O(5^log_10(N)) 이다.

총 시간 복잡도는 O(5^(log_10(N)) \* log_10(N)) 이다.

### 공간 복잡도

DFS를 사용할 경우 call stack에 사용하는 공간 복잡도는 O(log_10(N))이다.

### 정리

| 내 코드 (ms) |          시간 복잡도          | 공간 복잡도  |
| :----------: | :---------------------------: | :----------: |
|     1238     | O(5^(log_10(N)) \* log_10(N)) | O(log_10(N)) |

0, 1, 6, 8, 9에 대해서 탐색을 지속한다.

이 때 각 경우마다 confusing number가 가능한지에 대해 판단 후 정답에 포함한다.

또한 n을 넘지 않는 수에 대해서만 탐색해야 하므로 이에 대한 분기를 처리한다.

```cpp
int answer = 0;

unordered_map<int, int> um = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

bool isConfusingNumber(long n) {
  long src = n, res = 0;
  while (n > 0) {
    res = res * 10 + um[(int)n % 10];
    n /= 10;
  }
  return res != src;
}

void recursive(int n, long cur) {
  if (isConfusingNumber(cur)) {
    answer++;
  }
  for (auto &[key, val] : um) {
    if (cur * 10 + key == 0) continue;
    if (cur * 10 + key > n) continue;

    recursive(n, cur * 10 + key);
  }
}

int confusingNumberII(int N) {
  recursive(N, 0);

  return answer;
}
```

## 고생한 점
