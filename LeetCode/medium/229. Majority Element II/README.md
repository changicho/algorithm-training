# 229. Majority Element II

[링크](https://leetcode.com/problems/majority-element-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

값들을 순회하며 count 후 정답을 구할 경우 시간 복잡도는 O(N)이다.

보이어 무어 알고리즘을 사용할 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

count에 hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

보이어 무어 알고리즘을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

순회하며 count 후 정답을 구한다.

```cpp
vector<int> majorityElement(vector<int> &nums) {
  int size = nums.size();

  int limit = size / 3;
  unordered_map<int, int> um;

  for (int &num : nums) {
    um[num]++;
  }

  vector<int> answer;
  for (auto &[key, val] : um) {
    if (val > limit) {
      answer.push_back(key);
    }
  }
  return answer;
}
```

## 고생한 점
