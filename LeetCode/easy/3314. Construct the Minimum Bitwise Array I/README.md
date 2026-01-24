# 3314. Construct the Minimum Bitwise Array I

[링크](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

각 경우마다 직접 탐색을 할 경우 O(N \* M)의 시간 복잡도를 사용한다.

비트 연산을 이용해 값을 찾을 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다. 이는 거의 O(N)이다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 수마다 0부터 1000까지 완전 탐색을 하며 조건을 만족하는 가장 작은 수를 찾는다.

```cpp
vector<int> minBitwiseArray(vector<int>& nums) {
  int size = nums.size();

  vector<int> answer(size, -1);
  for (int i = 0; i < size; i++) {
    for (int num = 0; num <= 1000; num++) {
      if ((num | (num + 1)) == nums[i]) {
        answer[i] = num;
        break;
      }
    }
  }
  return answer;
}
```

## 고생한 점
