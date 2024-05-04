# 1885. Count Pairs in Two Arrays

[링크](https://leetcode.com/problems/count-pairs-in-two-arrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums1, 2의 길이를 N이라 하자.

모든 경우를 직접 판단할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

주어진 수식을 변경하면 각 index에 위치한 nums1, 2의 값을 이용해 판별할 수 있다.

따라서 각 index마다의 값을 구한 뒤 이를 이용해 풀이할 수 있다.

이를 구하는 데 O(N)의 시간 복잡도를 사용한다.

이후 정렬, 이분 탐색 혹은 투 포인터를 이용해 정답을 구할 수 있다.

이에 총 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

diff를 저장할 배열에 O(N)의 공간 복잡도를 사용한다.

### 수식 변경 & 정렬 & 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     154      | O(N \* log_2(N)) |    O(N)     |

주어진 수식을 아래와 같이 변경할 수 있다.

```cpp
// i < j에 대해서
nums1[i] + nums1[j] > nums2[i] + nums2[j]

// 위 값들의 위치를 변경하면 아래와 같다.
nums1[i] - nums2[i] > nums2[j] - nums1[j]
// 이는 아래와 같다.
nums1[i] - nums2[i] > -(nums1[j] - nums2[j])

// 여기서 -1을 곱하면 아래와 같다.
nums2[i] - nums1[i] < nums1[j] - nums2[j]
-(nums1[i] - nums2[i]) < nums1[j] - nums2[j]
```

즉 위 수식에 의해서 결국 두 배열의 index의 차이를 구한 뒤, 각 차이 diff들에 대해 해당 값들보다 큰것들을 찾으면 된다.

이를 이용해 각 차이들을 모두 구한 뒤 정렬 후 투 포인터를 이용해 정답을 구할 수 있다.

각 left, right에 대해서 현재 left에 있는 diff와 right에 있는 diff의 합이 0보다 크다면 right - left 만큼의 조건을 만족하는 경우가 존재한다.

따라서 answer에 right - left를 더해주고 right를 감소시킨다.

조건을 만족하지 않는경우 left를 증가시킨다.

```cpp
long long countPairs(vector<int>& nums1, vector<int>& nums2) {
  int size = nums1.size();
  vector<int> diffs;

  for (int i = 0; i < size; i++) {
    diffs.push_back(nums1[i] - nums2[i]);
  }

  sort(diffs.begin(), diffs.end());

  long long answer = 0;
  int left = 0, right = size - 1;
  while (left < right) {
    if (diffs[left] + diffs[right] > 0) {
      answer += right - left;
      right--;
    } else {
      left++;
    }
  }
  return answer;
}
```

### 수식 변경 & 정렬 & 이분탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     166      | O(N \* log_2(N)) |    O(N)     |

위 방법에서 현재 diff를 더했을 때 0보다 큰 경우의 갯수들을 이분탐색을 이용해 찾는다.

이 때 이미 지나온 값들은 무시해야 하므로 이분탐색의 범위를 제한한다.

```cpp
long long countPairs(vector<int>& nums1, vector<int>& nums2) {
  int size = nums1.size();
  vector<int> diff;

  for (int i = 0; i < size; i++) {
    diff.push_back(nums1[i] - nums2[i]);
  }

  sort(diff.begin(), diff.end());

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = diff[i];

    int count =
        diff.end() - upper_bound(diff.begin() + i + 1, diff.end(), -cur);
    answer += count;
  }
  return answer;
}
```

## 고생한 점
