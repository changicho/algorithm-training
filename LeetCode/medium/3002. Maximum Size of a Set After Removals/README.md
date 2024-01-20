# 3002. Maximum Size of a Set After Removals

[링크](https://leetcode.com/problems/maximum-size-of-a-set-after-removals/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums1, nums2의 크기를 N이라 하자.

각각의 수들을 벤다이어그램으로 생각한 뒤 중복되는 수들을 제거한다고 하자.

nums1, nums2의 수들을 각각 hash set에 저장하고, 두 배열의 수를 전부 hash set에 저장한다.

이후 각 hash set의 수들을 이용해 정답을 구할 수 있다.

이 경우 hash set에 저장하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     230      |    O(N)     |    O(N)     |

nums1 및 nums2의 수들을 각각의 hash set에 저장한다.

또한 두 배열에 있는 수를 전부 hash set에 저장한다.

정답은 다음 두 가지중 하나이다.

- 두 배열에 있는 모든 unique한 수
- 두 배열에서 각각 존재하는 unique한 수의 합.

문제 케이스에 다음과 같은 경우들이 존재한다.

- nums1, nums2에 있는 수들이 모두 unique한 경우 : 절반씩 삭제 후에도 모두 unique하다.
- nums1, nums2가 같은경우 : 각각 배열에서 절반씩 겹치지 않게 삭제할 수 있다.
- 모두 같은 수인경우 : 정답은 1이다.
- 일정 같은 수가 겹친 경우 : 겹친 수들을 우선 삭제할 수 있으며, 이 경우 한 배열에서 절반을 삭제 시에 남은 unique한 수는 N/2보다 작다.

이 때 정답은 N보다 클 수 없음에 유의한다.

```cpp
int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> us1, us2, usAll;
  int n = nums1.size();
  for (int x : nums1) {
    us1.insert(x);
    usAll.insert(x);
  }
  for (int x : nums2) {
    us2.insert(x);
    usAll.insert(x);
  }

  int answer = min(min(n / 2, (int)us1.size()) + min(n / 2, (int)us2.size()), (int)usAll.size());

  return answer;
}
```

## 고생한 점
