# 3510. Minimum Pair Removal to Sort Array II

[링크](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N이라 하자.

각 경우마다 최소 합 쌍을 구하는데 BST기반의 set이나 heap을 사용할 수 있다. 이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

매 경우마다 정렬을 만족하는지 판단을 직접 할 경우 O(N)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

수정해야 하는 갯수를 관리할 경우 O(1)의 시간 복잡도로 판단이 가능하다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이 된다.

### 공간 복잡도

각 합 쌍을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### set & linked list

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     855      | O(N \* log_2(N)) |    O(N)     |

각 경우마다 합이 최소가 되는 경우를 set에서 뽑아 사용한다.

이 때 연이은 두 수를 합치는 경우 각 숫자들의 연결관계에 변화가 생기므로 각 index마다 이전, 다음 index들을 linked list처럼 관리한다.

이 때 최초에 정렬 관계를 유지 하기 위해 수정되여야 하는 갯수를 관리하며, 각 합을 생성할 때마다 해당 갯수를 수정한다.

```cpp
int minimumPairRemoval(vector<int>& nums) {
  int size = nums.size();

  vector<long long> arr(size);
  for (int i = 0; i < size; i++) {
    arr[i] = nums[i];
  }

  // {sum, index}
  set<pair<long long, int>> s;

  vector<int> nextI(size);
  vector<int> prevI(size);
  for (int i = 0; i < size; i++) {
    nextI[i] = i + 1;
    prevI[i] = i - 1;
  }

  int needToSum = 0;
  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      needToSum++;
    }

    s.insert({arr[i] + arr[i + 1], i});
  }

  int answer = 0;
  while (needToSum > 0) {
    // prev - i - j - next
    int i = s.begin()->second;
    int j = nextI[i];
    int prev = prevI[i];
    int next = nextI[j];

    if (arr[i] > arr[j]) {
      needToSum--;
    }
    long long sum = arr[i] + arr[j];

    if (prev >= 0) {
      if (arr[prev] > arr[i] && arr[prev] <= sum) {
        needToSum--;
      } else if (arr[prev] <= arr[i] && arr[prev] > sum) {
        needToSum++;
      }
    }

    if (next < size) {
      if (arr[next] >= arr[j] && arr[next] < sum) {
        needToSum++;
      } else if (arr[next] < arr[j] && arr[next] >= sum) {
        needToSum--;
      }
    }

    s.erase(s.begin());
    if (prev >= 0) {
      s.erase({arr[prev] + arr[i], prev});
      s.insert({arr[prev] + sum, prev});
    }
    if (next < size) {
      s.erase({arr[j] + arr[next], j});
      s.insert({sum + arr[next], i});
      prevI[next] = i;
    }
    nextI[i] = next;
    arr[i] = sum;
    answer++;
  }

  return answer;
}
```

## 고생한 점
