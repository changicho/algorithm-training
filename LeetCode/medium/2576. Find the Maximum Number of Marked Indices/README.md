# 2576. Find the Maximum Number of Marked Indices

[링크](https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 길이를 N이라 하자. (N <= 10^5)

각 경우마다 직접 탐색할 경우 O(N!)의 시간 복잡도가 소요된다.

정렬 후 큰 값과 작은값을 나눈 뒤 이분 탐색을 사용할 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도가 소요된다.

작은 값을 순회하며 원소마다의 이분 탐색에 O(log_2(N))의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

큰 수를 저장할 공간에 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 이분탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     290      | O(N \* log_2(N)) |    O(N)     |

정답은 최대 N까지이며 2의 배수이다. (짝을 이루는 두 수의 종류들이므로)

각 원소들의 짝을 찾기 위해, 각 원소들을 큰값들과 작은값들로 나눈다.

이는 각 쌍의 작은 값들은 배열 내에서 큰 값들 내에서 짝을 찾는 편이 유리하기 때문이다.

이후 작은 값들을 순회하며 큰 값의 목록에 가능한 가장 적합한(작은) 값이 존재하는 지 판단하고 이를 제거한다.

이 때 N이 홀수인 경우, 중앙에 위치한 값은 큰값의 목록에 추가한다.

multiset을 이용해 값의 삭제와 이분 탐색을 구현한다.

```cpp
int maxNumOfMarkedIndices(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  multiset<int> bigger;
  for (int i = size / 2; i < size; i++) {
    int num = nums[i];
    bigger.insert(num);
  }

  int count = 0;
  for (int i = 0; i < size / 2; i++) {
    auto it = bigger.lower_bound(nums[i] * 2);

    if (it != bigger.end()) {
      bigger.erase(it);
      count += 2;
    }
  }

  return count;
}
```

## 고생한 점
