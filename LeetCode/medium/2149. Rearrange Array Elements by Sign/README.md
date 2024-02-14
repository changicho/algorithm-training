# 2149. Rearrange Array Elements by Sign

[링크](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

음수와 양수를 나눈 후 새로운 배열을 생성할 수 있다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도가 필요하다.

큐에 O(N)의 공간 복잡도가 필요하다.

### 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     144      |    O(N)     |    O(N)     |

양수와 음수를 나눈 후 큐에 넣고 순서대로 정답 배열에 넣는다.

```cpp
vector<int> rearrangeArray(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer;

  queue<int> negative, positive;
  for (int& num : nums) {
    if (num < 0) {
      negative.push(num);
    } else {
      positive.push(num);
    }
  }

  for (int i = 0; i < size / 2; i++) {
    answer.push_back(positive.front());
    answer.push_back(negative.front());
    positive.pop();
    negative.pop();
  }
  return answer;
}
```

## 고생한 점
