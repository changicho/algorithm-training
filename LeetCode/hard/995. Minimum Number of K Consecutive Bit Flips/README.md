# 995. Minimum Number of K Consecutive Bit Flips

[링크](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 수를 K라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* K) 이므로 제한시간 내에 불가능하다.

왼쪽부터 순회하며 유효한 flip의 count를 유지하며 valid한지 판단할 수 있다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 index 마다 flip이 필요한지 여부를 판단해야 하므로 O(N)의 공간 복잡도가 필요하다.

### flip count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      81      |    O(N)     |    O(N)     |

왼쪽부터 순회하며 현재 index의 수를 뒤집어야 하는 경우 flip을 수행한다.

이 때 직접 K개의 숫자를 뒤집을 경우 제한시간 내에 불가능하다.

따라서 현재 flip된 갯수를 이용해 현재 index가 몇번 뒤집어졌는지를 판단한다.

flip된 갯수는 index가 증가함에 따라 증가, 감소하므로 이를 이용한다.

```cpp
int minKBitFlips(vector<int>& nums, int k) {
  int size = nums.size();

  vector<bool> isFlipped(size, false);
  int count = 0;
  int answer = 0;

  for (int i = 0; i < size; i++) {
    if (i >= k && isFlipped[i - k]) {
      count--;
    }

    if (count % 2 == nums[i]) {
      if (i + k > size) {
        return -1;
      }

      count++;
      isFlipped[i] = true;
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
