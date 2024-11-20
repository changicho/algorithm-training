# 1829. Maximum XOR for Each Query

[링크](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

각 숫자들의 비트들을 모두 센 뒤 현재 포함된 num들과 만들 수 있는 최대 XOR 값을 구해야 한다.

각 비트별로 미리 합을 구해놓을 경우 O(1)의 시간 복잡도로 XOR값을 구할 수 있다.

이를 모든 수에 대해 반복할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 비트를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### xor with mask

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

nums의 모든 수를 XOR 연산한 값을 구한다.

이후 nums의 마지막 값부터 해당 XOR 값에서 다시 XOR 연산을 수행해 현재까지 포함된 nums들의 XOR 값을 구할 수 있다.

현재 수들의 XOR 값을 알고 있으므로 해당 비트에서 빈 비트를 채워넣을 경우 최대값을 만들 수 있다.

이 때 maximumBit 자리까지 채울 수 있다.

비트의 갯수가 maximumBit인 모두 1로 이루어진 마스크 비트를 생성한 뒤 현재 XOR 값과 XOR 연산을 수행한다.

이 경우 0인 비트들만 1로 채워지므로 최대값을 만들 수 있다.

```cpp
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
  int xors = 0;
  for (int& num : nums) {
    xors ^= num;
  }
  int mask = (1 << maximumBit) - 1;

  vector<int> answer;
  while (!nums.empty()) {
    int cur = xors ^ mask;

    answer.push_back(cur);

    xors ^= nums.back();
    nums.pop_back();
  }

  return answer;
}
```

## 고생한 점
