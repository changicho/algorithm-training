# 2419. Longest Subarray With Maximum Bitwise AND

[링크](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

AND연산을 수행할 경우 두 수가 같지 않은 경우 결과값은 점점 줄어든다.

따라서 배열의 가장 큰 수가 연속된 횟수를 구해야 한다.

이를 위해 한번 순회를 통해 가장 큰 수를 찾고, 다시 한번 순회를 통해 연속된 수를 찾아야 한다. 이 경우 O(N)의 시간 복잡도가 필요하다.

한번의 순회로 큰 수를 찾고 연속된 수를 카운트 할 수 있다. 이 시간 복잡도는 O(N)이다.

### 공간 복잡도

수의 갯수만 저장하면 되므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     110      |    O(N)     |    O(1)     |

각 과정마다 이전값과 같은 연속된 수의 count를 증가시키고, maximum 값이 갱신될 때마다 count한 answer를 갱신한다.

```cpp
int longestSubarray(vector<int>& nums) {
  int answer = 0;
  int maximum = -1;

  int before = -1;
  int count = 0;
  for (int& cur : nums) {
    if (before == cur) {
      count++;
    } else {
      before = cur;
      count = 1;
    }

    if (before > maximum) {
      answer = count;
      maximum = before;
    } else if (cur == maximum) {
      answer = max(answer, count);
    }
  }
  return answer;
}
```

## 고생한 점
