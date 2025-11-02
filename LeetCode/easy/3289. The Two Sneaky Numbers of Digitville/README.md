# 3289. The Two Sneaky Numbers of Digitville

[링크](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

갯수를 세 풀이할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

갯수를 세는데 O(N)의 공간 복잡도를 사용한다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

```cpp
vector<int> getSneakyNumbers(vector<int>& nums) {
  vector<int> answer;

  int count[101] = {
      0,
  };
  for (int& num : nums) {
    count[num]++;
  }

  for (int i = 0; i <= 100; i++) {
    if (count[i] == 2) answer.push_back(i);
  }
  return answer;
}
```

## 고생한 점
