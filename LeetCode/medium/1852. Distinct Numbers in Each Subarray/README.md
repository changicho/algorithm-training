# 1852. Distinct Numbers in Each Subarray

[링크](https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

각 수를 저장할 때 hash map을 사용해 종류와 갯수를 저장한다. 이 경우 매 경우마다 O(1)의 시간 복잡도로 수를 저장할 수 있다.

### 공간 복잡도

슬라이딩 윈도우에 O(K)의 공간 복잡도가 필요하다.

정답에 O(N - K)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     268      |    O(N)     |    O(N)     |

크기가 K인 슬라이딩 윈도우를 사용해 윈도우의 수의 종류를 구한다.

이를 위해 hash map을 사용하며, 윈도우에서 수를 삭제할 때 hash map의 count를 감소시키고 0이 되면 삭제한다.

```cpp
vector<int> distinctNumbers(vector<int>& nums, int k) {
  unordered_map<int, int> counts;

  int size = nums.size();

  vector<int> answer;
  for (int i = 0; i < k; i++) {
    counts[nums[i]]++;
  }
  answer.push_back(counts.size());

  for (int i = k; i < size; i++) {
    counts[nums[i]]++;
    counts[nums[i - k]]--;
    if (counts[nums[i - k]] == 0) counts.erase(nums[i - k]);

    answer.push_back(counts.size());
  }

  return answer;
}
```

## 고생한 점
