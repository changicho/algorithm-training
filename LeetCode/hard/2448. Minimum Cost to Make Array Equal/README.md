# 2448. Minimum Cost to Make Array Equal

[링크](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N, 값들 중 가장 큰 값을 M이라 하자. (1 <= N <= 10^5, 1<= M <= 10^6)

정답은 1 ~ M의 범위의 숫자중 하나임이 보장된다.

하나의 값에 대해 cost들의 합을 구하는 데 O(N)의 시간 복잡도를 사용한다.

이를 모두 탐색할 경우 O(N \* M)의 시간 복잡도를 사용하며, 이는 제한시간 내에 불가능하다.

1 ~ M에 대해서 이분탐색, 삼분탐색을 사용할 수 있다.

이 때 각 cost는 정답에서 가장 낮고, 정답에서 멀어질수록 증가하는 구조가 된다.

이 경우 시간 복잡도는 이분탐색을 사용할 때 O(N \* log_2(M))가 된다.

삼분탐색을 사용할 때 O(N \* log\_(3/2)(N))이 된다.

(삼분탐색의 경우 실제로는 4 \* log_3(N)의 시간 복잡도를 사용하며 앞에 상수만큼 곱해지므로 실제로는 이분탐색보다 시간이 오래걸린다.)

### 공간 복잡도

각 cost의 합을 구하는 데 O(1)의 공간 복잡도를 사용한다.

이분 탐색을 사용하는데 상수크기의 공간 복잡도를 사용한다.

### 삼분 탐색

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     269      | O(N \* log\_(3/2)(N)) |    O(1)     |

특정 숫자 X로 배열의 숫자들을 변경했을 때 cost의 합을 그래프로 그려볼 경우, 최솟값(정답) 이외의 경우 단조롭게 증가하는 형태의 그래프가 된다.

따라서 삼분 탐색을 이용해 최소 지점을 구할 수 있다.

삼분 탐색의 경우 각 범위마다 다음 탐색시 2/3으로 범위를 줄여나가며 탐색을 진행한다.

탐색하는 범위 left ~ right를 삼분 탐색으로 줄이고, 이후 해당 범위에 있는 정답을 구한다.

이 경우 while문을 탈출할 때 범위의 크기는 최대 3이므로 상수 시간 내에 정답을 구할 수 있다.

```cpp
long long getCostSum(vector<int>& nums, vector<int>& cost, int target) {
  int size = nums.size();

  long long costSum = 0;
  for (int i = 0; i < size; i++) {
    costSum += abs(target - nums[i]) * (long long)cost[i];
  }
  return costSum;
}

long long minCost(vector<int>& nums, vector<int>& cost) {
  long long answer = LLONG_MAX;

  int left = nums.front(), right = nums.front();
  for (int& num : nums) {
    left = min(left, num);
    right = max(right, num);
  }

  while (left + 3 <= right) {
    int leftPart = (2 * left + right) / 3;
    int rightPart = (left + 2 * right) / 3;

    long long costL = getCostSum(nums, cost, leftPart);
    long long costR = getCostSum(nums, cost, rightPart);

    if (costL < costR) {
      right = rightPart;
    } else {
      left = leftPart;
    }
  }

  for (int i = left; i <= right; i++) {
    answer = min(answer, getCostSum(nums, cost, i));
  }

  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     154      | O(N \* log_2(N)) |    O(1)     |

이분 탐색을 수행할 때, 중앙값을 M이라 하자.

M, (M+1) 두 값에 대해서 cost를 구하고 cost가 낮아지는 방향으로 이동해 최솟값을 탐색할 수 있다. (각 과정마다 값이 작아지는 방향으로 이동함)

이를 구현하면 다음과 같다.

```cpp
long long getCostSum(vector<int>& nums, vector<int>& cost, int target) {
  int size = nums.size();

  long long costSum = 0;
  for (int i = 0; i < size; i++) {
    costSum += abs(target - nums[i]) * (long long)cost[i];
  }
  return costSum;
}

long long minCost(vector<int>& nums, vector<int>& cost) {
  int left = nums.front(), right = nums.front();
  for (int& num : nums) {
    left = min(left, num);
    right = max(right, num);
  }
  right++;

  long long answer = getCostSum(nums, cost, left);

  while (left < right) {
    int mid = left + (right - left) / 2;
    long long costMidL = getCostSum(nums, cost, mid),
              costMidR = getCostSum(nums, cost, mid + 1);
    answer = min(costMidL, costMidR);

    if (costMidL < costMidR) {
      // pick left part
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  return answer;
}
```

## 고생한 점
