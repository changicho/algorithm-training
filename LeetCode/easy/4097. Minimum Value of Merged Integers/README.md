# 4097. Minimum Value of Merged Integers

[링크](https://leetcode.com/problems/minimum-value-of-merged-integers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

연이은 수를 이용해 새로운 수를 만드는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회 및 숫자 생성에 O(1)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int minMergedInteger(vector<int>& nums) {
  int size = nums.size();
  int answer = INT_MAX;

  for (int i = 0; i < size; i += 2) {
    int cur = nums[i] * pow(10, (int)log10(nums[i + 1]) + 1) + nums[i + 1];

    answer = min(answer, cur);
  }
  return answer;
}
```

## 고생한 점
