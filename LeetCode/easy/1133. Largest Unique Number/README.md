# 1133. Largest Unique Number

[링크](https://leetcode.com/problems/largest-unique-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 각 원소의 최대값을 M이라 하자.

모든 원소를 순회하며 각 원소의 개수를 세는데 O(N)의 시간 복잡도가 필요하다.

이후 갯수가 한개인 원소를 찾아야 하므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 원소의 개수를 저장할 배열이 필요하다. 이 배열에 O(M)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(M)     |

각 수를 카운팅 한 뒤 1개인 원소 중 정답을 찾는다.

```cpp
int largestUniqueNumber(vector<int> &nums) {
  int counts[1001] = {
      0,
  };
  int answer = -1;
  for (int &num : nums) {
    counts[num]++;
  }

  for (int &num : nums) {
    if (counts[num] == 1) {
      answer = max(answer, num);
    }
  }
  return answer;
}
```

## 고생한 점
