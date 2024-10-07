# 1497. Check If Array Pairs Are Divisible by k

[링크](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 입력 받은 수를 K라 하자.

각 수마다 나머지를 구하고, 다른 나머지쌍을 더해서 나누어 떨어지는 경우를 판단할 수 있다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

나머지를 저장할 배열을 생성해야 하므로 O(K)의 공간 복잡도가 필요하다.

### 순회 & 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      90      |    O(N)     |    O(K)     |

각 수마다 다른 수를 더했을 때 K로 나누어 떨어지는지 판단하기 위해 나머지 값을 사용할 수 있다.

각 수를 K로 나눈 나머지들을 구한 뒤, 해당 값들 중 두 값을 더했을 때 K가 되는 경우 두 수를 더하면 K로 나누어 떨어지는 경우이다.

이 때 각 수가 음수일 수도 있으므로 음수인 경우는 나머지를 양수로 변환한다.

```cpp
bool canArrange(vector<int>& arr, int k) {
  vector<int> mods(k, 0);

  for (int& num : arr) {
    int mod = num % k;
    mod = (mod + k) % k;

    int other = (k - mod) % k;

    if (mods[other] > 0) {
      mods[other]--;
    } else {
      mods[mod]++;
    }
  }

  for (int i = 0; i < k; i++) {
    if (mods[i] > 0) return false;
  }
  return true;
}
```

## 고생한 점
