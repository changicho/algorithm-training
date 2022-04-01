# 2190. Most Frequent Number Following Key In an Array

[링크](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

key 이후에 나오는 숫자들을 count해야 한다. 이를 hash map을 이용해 count한다.

이 경우 한번 순회를 해야 하므로 O(N)의 시간 복잡도를 사용한다.

이후 hash map의 각 원소들 중 가장 count가 큰 값을 선택한다. 이는 최악의 경우 O(N)이다.

### 공간 복잡도

hash map을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

원소를 순회하며 현재 원소가 key인 경우 다음 숫자를 count한다.

이후 가장 많이 count한 숫자를 찾아 반환한다.

```cpp
int mostFrequent(vector<int>& nums, int key) {
  int size = nums.size();
  unordered_map<int, int> count;

  for (int i = 0; i < size; i++) {
    if (nums[i] == key && i + 1 < size) {
      count[nums[i + 1]]++;
    }
  }

  int answer = nums.front();
  for (auto it : count) {
    if (count[it.first] > count[answer]) {
      answer = it.first;
    }
  }

  return answer;
}
```

## 고생한 점

문제를 제대로 이해하는데 오래걸렸다.

> target immediately follows an occurrence of key in nums
