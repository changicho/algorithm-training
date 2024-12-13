# 2779. Maximum Beauty of an Array After Applying Operation

[링크](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 후 이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     129      | O(N \* log_2(N)) |    O(N)     |

정답에 포함되는 범위를 최대한 유리하게 하기 위해, 범위의 끝값에 nums의 원소중 하나가 포함되도록 구성한다.

각 과정마다 이분 탐색을 사용해 범위에 해당하는 수를 빠르게 찾는다.

이를 위해 nums를 정렬한다.

이후 각 숫자를 순회하며 현재 숫자를 num이라 했을 때 아래 범위의 수의 갯수를 찾는다.

- num ~ num + 2 \* k
- num - 2 \* k ~ num

둘 중 하나의 기준으로 탐색해도 결국에는 가장 유리한 값을 선택하므로 정답은 동일하게 탐색된다.

```cpp
int maximumBeauty(vector<int>& nums, int k) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int answer = 0;

  for (int& num : nums) {
    int count = upper_bound(nums.begin(), nums.end(), num + 2 * k) -
                lower_bound(nums.begin(), nums.end(), num);

    answer = max(answer, count);
  }

  return answer;
}
```

## 고생한 점
