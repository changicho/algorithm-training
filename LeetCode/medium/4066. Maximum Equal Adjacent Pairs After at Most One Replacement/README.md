# 4066. Maximum Equal Adjacent Pairs After at Most One Replacement

[링크](https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 연이은 쌍의 종류의 수를 M이라 하자.

갯수를 센 뒤 쌍의 종류를 순회하며 정답을 갱신할 경우 O(N + M)의 시간 복잡도를 사용한다.

순회와 동시에 최적쌍을 갱신할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

수의 갯수를 세는 데 O(N)의 공간 복잡도를 사용한다.

### 쌍의 수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     339      |    O(N)     |    O(N)     |

연이은 2개 수의 쌍의 수를 저장한다.

이 때 A->B, B->A 의 경우 같은 쌍으로 취급한다.

이미 연속된 숫자 쌍이 같은 수인 경우 이미 같은쌍의 수를 증가시키고, 다른 경우 해당 카운트를 증가시킨다.

이 과정에서 해당 쌍의 수 중 가장 큰 갯수를 구한다.

이미 같은 쌍의 수와 가장 많은 쌍의 수를 더한 값이 정답이 된다.

```cpp
int maxEqualAdjacentPairs(vector<int>& nums) {
  int alreadySame = 0;
  int sameMax = 0;

  unordered_map<long long, int> count;

  int size = nums.size();

  for (int i = 0; i < size - 1; i++) {
    int a = min(nums[i], nums[i + 1]), b = max(nums[i], nums[i + 1]);

    if (a == b) {
      alreadySame++;
    } else {
      long long key = ((long long)a << 32) + b;
      count[key]++;
      sameMax = max(sameMax, count[key]);
    }
  }
  return alreadySame + sameMax;
}
```

## 고생한 점
