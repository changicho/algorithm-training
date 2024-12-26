# 2762. Continuous Subarrays

[링크](https://leetcode.com/problems/continuous-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

모든 경우를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우와 BST map을 사용할 경우 O(N \* log_2(K))의 시간 복잡도로 해결이 가능하다.

이 떄 BST map에는 유효한 수만 저장하며 이 범위는 최대 -2 ~ +2 까지이므로 이는 거의 상수이다. 따라서 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 O(N)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |    O(N)     |    O(N)     |

슬라이딩 윈도우를 이용해 현재 수를 윈도우에 포함했을 때 문제 조건을 만족하는지 판단한다.

이 때 수의 범위를 맞춰야 하므로 BST map을 이용해 범위를 벗어나는 수가 있는지 이분 탐색을 이용해 판단한다.

이 때 범위는 현재 숫자의 -2 ~ +2 의 범위를 벗어나는 수가 있는지 판단한다.

```cpp
bool isValid(map<int, int>& count, int val) {
  if (count.lower_bound(val - 2) != count.begin()) return false;
  if (count.lower_bound(val + 2 + 1) != count.end()) return false;
  return true;
}

long long continuousSubarrays(vector<int>& nums) {
  int size = nums.size();

  long long answer = 0;

  map<int, int> count;

  for (int left = 0, right = 0; right < size; right++) {
    int cur = nums[right];

    while (left < right && !isValid(count, cur)) {
      count[nums[left]]--;

      if (count[nums[left]] == 0) {
        count.erase(nums[left]);
      }
      left++;
    }

    count[cur]++;
    int length = right - left + 1;

    answer += length;
  }
  return answer;
}
```

## 고생한 점
