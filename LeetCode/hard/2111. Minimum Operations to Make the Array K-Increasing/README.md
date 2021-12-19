# 2111. Minimum Operations to Make the Array K-Increasing

[링크](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

arr의 원소의 개수를 N, 입력받은 수를 K라 하자.

arr의 원소에 대해서 i, i+K 번째에 대해 비교를 수행해야한다.

따라서 k개의 배열을 만들고 비교를 해야할 원소들 끼리 묶는다. 이 연산에 O(N)의 시간 복잡도가 소요된다.

이후 LIS알고리즘을 이용해 감소하지 않는 가장 긴 수열을 찾는다.

해당 수열 외에 남은 숫자를 변환했을 때가 최소 변환이 되기 때문이다.

따라서 각 배열마다 LIS 알고리즘을 수행했을 때 시간 복잡도는 O((N / K) \* log_2(N / K))이다. (배열에 들어가는 원소는 N / K개 이므로)

이를 K번 반복할 경우 최종 시간 복잡도는 O(N \* log_2(N / K))이다.

### 공간 복잡도

LIS를 사용하기 위해 cache역할을 할 배열을 생성한다.

이 배열의 크기는 O(N)이므로 O(N)의 공간 복잡도를 사용한다.

### LIS 응용 - Longest Non-Decreasing Subsequence

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     320      | O(N \* log_2(N / K)) |    O(N)     |

각 원소들은 i, i+k씩 비교하게 되므로 (모든 i에 대해서) k개의 묶음으로 구분할 수 있다.

따라서 해당 묶음들 끼리는 i, i+1번째 끼리 문제 조건에 맞게 비교하면 된다.

해당 묶음에서 최소로 바꿔야 하는 비용은, 문제 조건에 맞지 않는 최소 부분들만 바꾸는 경우이다.

문제 조건에 맞는 경우는 i번째 수가 i+1번째 이하인 경우이다.

LIS 알고리즘을 이용하면 최장 증가 수열을 구할 수 있다. 여기서 LIS알고리즘은 초과인 경우에 대해서 탐색하므로 이를 살짝 변형해 사용한다.

이 때 O(N^2)의 방법을 사용할 경우 제한시간 내에 불가능하므로 O(N \* log_2(N))의 방법을 사용한다.

```cpp
// 일반 LIS
vector<int> getLIS(vector<int> &arr){
  int size = arr.size();
  vector<int> lis;

  for (int i = 0; i < size; i++) {
    // lower_bound를 이용하므로 arr[i]값이 기존에 존재하는 경우도 바꾼다.
    int target = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

    if (target == lis.size()) {
      lis.push_back(arr[i]);
    } else {
      lis[target] = arr[i];
    }
  }

  return lis;
}
```

위 알고리즘에서 lower_bound부분을 upper_bound로 수정할 경우 현재 값을 갈아 끼울 때 초과분에 대해서만 바꾸므로 수열에서 중복된 원소를 포함할 수 있다.

이를 이용해 각 묶음들에서 수정할 부분의 최소 개수를 구할 수 있다.

```cpp
int getMinimumChange(vector<int> &list) {
  int size = list.size();
  vector<int> lis;

  for (int i = 0; i < size; i++) {
    int target = upper_bound(lis.begin(), lis.end(), list[i]) - lis.begin();

    if (target == lis.size()) {
      lis.push_back(list[i]);
    } else {
      lis[target] = list[i];
    }
  }

  return size - lis.size();
}

int kIncreasing(vector<int> &arr, int k) {
  vector<vector<int>> lists(k);
  int size = arr.size();

  for (int i = 0; i < size; i++) {
    lists[i % k].push_back(arr[i]);
  }

  int answer = 0;
  for (vector<int> &list : lists) {
    answer += getMinimumChange(list);
  }

  return answer;
}
```

## 고생한 점
