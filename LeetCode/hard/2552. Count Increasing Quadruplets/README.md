# 2552. Count Increasing Quadruplets

[링크](https://leetcode.com/problems/count-increasing-quadruplets/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수의 크기를 N이라 하자. (N <= 4,000)

각 값들은 유일하며 최소값은 1이며 최대값은 N이다.

i,j,k,l을 구하기 위해 모든 경우를 탐색할 경우 O(N^4)의 시간 복잡도를 사용한다.

j,k를 순회하며 직전에 특정 위치에서의 특정 값 이하, 이상의 수를 찾아 정답을 구할 수 있다.

이 때 특정 위치에서의 값을 빠르게 찾기 위해 미리 저장해두고 사용하는 동적 계획법을 사용할 수 있다.

혹은 각 과정마다의 vector를 정렬해 사용할 수 있다.

매번 정렬 할 경우 각 index마다 vector를 생성하는데 O(N), 내부에서 값을 채우고 정렬하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이 경우 dp를 갱신하는데 O(N^2)의 시간 복잡도를, j, k에 대해 순회하는데 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 값, index에 대한 dp를 생성하는 데 O(N^2)의 시간 복잡도를 사용한다.

### 정렬 & 이분탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     2056     | O(N^2 \* log_2(N)) |   O(N^2)    |

j, k를 순회하며 j번째 값이 k번째 값보다 큰 경우들을 찾는다.

이후 두 값을 곱할 경우 현재 가능한 경우의 수가 나온다.

- k번째 값보다 작은 j 왼쪽 값의 수
- j번째 값보다 큰 k 오른쪽 값의 수

여기서 각 k, j번째보다 작거나 큰 왼쪽, 오른쪽 수를 구하기 위해 다음과 같은 배열을 사용한다.

```cpp
vector<int> lefts[i]; // 왼쪽에서 부터 i번째 까지 값들이 정렬되어있는 배열
vector<int> rights[i]; // 오른쪽에서 부터 i번째 까지 값들이 정렬되어 있는 배열
```

이후 각 j, k를 순회하며 각 수를 구하는 데 이분 탐색을 이용해 빠르게 구한다.

이 때 실행 시간을 최적화 하기 위해 정렬시에 삽입 정렬을 사용한다.

```cpp
long long countQuadruplets(vector<int>& nums) {
  int size = nums.size();

  vector<int> lefts[4001], rights[4001];

  for (int i = 0; i < size; i++) {
    if (i - 1 >= 0) lefts[i] = lefts[i - 1];

    auto target = lower_bound(lefts[i].begin(), lefts[i].end(), nums[i]);
    lefts[i].insert(target, nums[i]);
  }
  for (int i = size - 1; i >= 0; i--) {
    if (i + 1 < size) rights[i] = rights[i + 1];
    auto target = lower_bound(rights[i].begin(), rights[i].end(), nums[i]);
    rights[i].insert(target, nums[i]);
  }

  long long answer = 0;
  for (int j = 1; j < size - 1; j++) {
    for (int k = j + 1; k < size - 1; k++) {
      if (nums[j] <= nums[k]) continue;

      int leftCounts =
          (lower_bound(lefts[j - 1].begin(), lefts[j - 1].end(), nums[k]) -
            lefts[j - 1].begin());
      int rightCounts =
          rights[k + 1].size() -
          (upper_bound(rights[k + 1].begin(), rights[k + 1].end(), nums[j]) -
            rights[k + 1].begin());

      // valid case
      answer += leftCounts * rightCounts;
    }
  }

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1486     |   O(N^2)    |   O(N^2)    |

위 방법에서 j, k에 대해 왼쪽 오른쪽에 있는 수를 빠르게 구하기 위해 동적 계획법을 사용한다.

다음과 같은 dp 배열을 선언한다.

```cpp
int lessThan[num][i]; // the number of elements less than `num` in the first i elements of nums.
int greaterThan[num][i]; // the number of elements more than `num` in the last i elements of nums.

for (int num = 1; num <= size; num++) {
  for (int i = 1; i <= size; i++) {
    lessThan[num][i] = lessThan[num][i - 1] + (nums[i - 1] < num);
  }
}
for (int num = size; num >= 1; num--) {
  for (int i = size - 1; i >= 1; i--) {
    greaterThan[num][i] = greaterThan[num][i + 1] + (nums[i] > num);
  }
}
```

이 방법을 이용해 각 값에 대해 왼쪽, 오른쪽에 존재하는 수를 O(1)의 시간 복잡도로 구할 수 있다.

```cpp
long long countQuadruplets(vector<int>& nums) {
  int size = nums.size();

  // lessThan[num][i]; the number of elements less than `num` in the first i
  // elements of nums.
  vector<vector<int>> lessThan(size + 1, vector<int>(size + 2, 0));
  vector<vector<int>> greaterThan(size + 1, vector<int>(size + 2, 0));

  for (int num = 1; num <= size; num++) {
    for (int i = 1; i <= size; i++) {
      lessThan[num][i] = lessThan[num][i - 1] + (nums[i - 1] < num);
    }
  }
  for (int num = size; num >= 1; num--) {
    for (int i = size - 1; i >= 1; i--) {
      greaterThan[num][i] = greaterThan[num][i + 1] + (nums[i] > num);
    }
  }

  long long answer = 0;
  for (int j = 1; j < size - 2; j++) {
    for (int k = j + 1; k < size - 1; k++) {
      if (nums[j] > nums[k]) {
        int right = greaterThan[nums[j]][k];
        int left = lessThan[nums[k]][j];

        answer += right * left;
      }
    }
  }
  return answer;
}
```

### 동적 계획법 (최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     973     |   O(N^2)    |   O(N^2)    |

위 방법에서 원소들의 값의 범위와 유일한 값들을 가지는 것을 이용해 하나의 dp만으로 두 경우를 모두 구할 수 있다.

위 값에서 lessThan을 남기고 이후 greaterThan을 구하는 경우를 아래와 같이 구한다.

```cpp
// 1. lessThan을 이용해 왼쪽에서 부터 k개의 값들 중 nums[j]보다 큰 값의 수를 센다.
(k - lessThan[nums[j]][k + 1]);
// 2. N - nums[j] 개 만큼 nums[j]보다 큰 값이 전체 값들 중 존재할 수 있다.
(size - nums[j]);
// 3. 1번에서 구한 갯수를 2번에서 구한 갯수에서 뺀다.
(size - nums[j]) - (k - lessThan[nums[j]][k + 1]);
```

이를 이용해 구하면 다음과 같다.

```cpp
long long countQuadruplets(vector<int>& nums) {
  int size = nums.size();

  // lessThan[num][i]; the number of elements less than `num` in the first i
  // elements of nums.
  vector<vector<int>> lessThan(size + 1, vector<int>(size + 2, 0));

  for (int num = 1; num <= size; num++) {
    for (int i = 1; i <= size; i++) {
      lessThan[num][i] = lessThan[num][i - 1] + (nums[i - 1] < num);
    }
  }

  long long answer = 0;
  for (int j = 1; j < size - 2; j++) {
    for (int k = j + 1; k < size - 1; k++) {
      if (nums[j] > nums[k]) {
        int right = (size - nums[j]) - (k - lessThan[nums[j]][k + 1]);
        int left = lessThan[nums[k]][j];

        answer += right * left;
      }
    }
  }
  return answer;
}
```

## 고생한 점
