# 3551. Minimum Swaps to Sort by Digit Sum

[링크](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

각 숫자마다 주어진 조건에 따라 변환해 우선순위를 판단하므로 O(N \* log_10(M))의 시간 복잡도를 사용한다.

이후 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 이동시켜야 하는 위치들에 따른 사이클의 수를 센다. 이에 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* (log_2(N) + log_10(M))) 이다.

### 공간 복잡도

변환, 정렬과 사이클을 판단하는데 O(N)의 공간 복잡도를 사용한다.

### 정렬 & cycle 카운트

| 내 코드 (ms) |          시간 복잡도           | 공간 복잡도 |
| :----------: | :----------------------------: | :---------: |
|     966      | O(N \* (log_2(N) + log_10(M))) |    O(N)     |

배열의 원소들을 다음과 같이 3가지 값을 갖는 데이터로 변환한다.

- 각 자리수의 합
- 원본 값
- index

이후 위 순서대로 우선순위로 정렬 후 원본 배열에서 해당 숫자가 이동해야 하는 위치를 알 수 있다.

이제 각 숫자들을 이동시켜야 할 때 이동하는 숫자들을 탐색하며 해당 숫자들의 묶음인 cycle의 수를 센다.

각 cycle을 구성하는 원소의 수를 `k[i]`라 하자.

하나의 사이클을 올바른 위치로 옮기는 이동 횟수는 `k[i] - 1` 이다.

따라서 정답은 아래와 같이 구성된다.

```cpp
for(int cycle : cycles){
  answer += cycle - 1;
}

// 여기서 cycle의 총 합은 N이다.
answer = N - cycles.size();
```

따라서 정답은 원소의 갯수에서 사이클의 수를 뺀 값이 된다.

```cpp
vector<int> convert(int num, int index) {
  int origin = num;

  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return {sum, origin, index};
}

int minSwaps(vector<int>& nums) {
  int size = nums.size();
  vector<vector<int>> converted;

  for (int i = 0; i < size; i++) {
    vector<int> cur = convert(nums[i], i);

    converted.push_back(cur);
  }

  sort(converted.begin(), converted.end());

  vector<int> nextIndexes;
  for (int i = 0; i < size; i++) {
    nextIndexes.push_back(converted[i][2]);
  }

  vector<int> visited(size);
  int cycleCount = 0;
  for (int i = 0; i < size; i++) {
    if (!visited[i]) {
      cycleCount++;

      int next = i;
      while (!visited[next]) {
        visited[next] = true;
        next = nextIndexes[next];
      }
    }
  }

  return size - cycleCount;
}
```

## 고생한 점
