# 2364. Count Number of Bad Pairs

[링크](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

수식의 변경을 이용해 이전 값들을 count하며 순회해 풀이할 수 있다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

순회하며 지나온 값을 count하는 데 O(N)의 공간 복잡도가 필요하다.

### 순회 & hash map count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      55      |    O(N)     |    O(N)     |

주어진 수식은 다음과 같다.

```cpp
j - i != nums[j] - nums[i];

// 이를 변환하면 아래와 같다.
j - nums[j] != i - nums[i];
```

따라서 현재 index와 현재값을 이용해 이전 순회한 값들과 비교하며 경우의 수를 구할 수 있다.

```cpp
long long countBadPairs(vector<int>& nums) {
  long long answer = 0;

  int size = nums.size();
  unordered_map<int, int> counts;

  for (int i = 0; i < size; i++) {
    int cur = i - nums[i];

    answer += i - counts[cur];
    counts[cur]++;
  }
  return answer;
}
```

## 고생한 점
