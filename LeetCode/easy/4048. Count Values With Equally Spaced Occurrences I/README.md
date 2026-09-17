# 4048. Count Values With Equally Spaced Occurrences I

[링크](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 값마다 index를 hash map에 저장 후 판단할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

각 값마다 index를 순차적으로 저장 후 index가 3개인 값의 경우 정답인지 판단한다.

```cpp
int countSpecialIntegers(vector<int>& nums) {
  int size = nums.size();
  unordered_map<int, vector<int>> indexs;

  for (int i = 0; i < size; i++) {
    indexs[nums[i]].push_back(i);
  }

  int answer = 0;
  for (auto& [num, is] : indexs) {
    if (is.size() != 3) continue;

    if (is[2] - is[1] == is[1] - is[0]) answer++;
  }
  return answer;
}
```

## 고생한 점
