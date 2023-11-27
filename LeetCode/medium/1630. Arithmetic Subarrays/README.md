# 1630. Arithmetic Subarrays

[링크](https://leetcode.com/problems/arithmetic-subarrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 쿼리의 갯수를 M이라 하자.

각 쿼리마다 배열 구간의 원소에 대해 등차수열인지 판별해야 한다. 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이를 M번 반복하면 되므로 O(M \* N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      38      | O(M \* N \* log_2(N)) |    O(N)     |

특정 숫자들이 등차수열을 이루는지 판별하기 위해 정렬을 이용할 수 있다.

수를 오름차순으로 정렬 후 각 수들의 차이가 모두 같은지 판별한다.

이를 M번 반복하며, 각 쿼리마다 별도의 배열을 만들어 정렬한다.

```cpp
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
  int qSize = l.size();

  vector<bool> answer;

  for (int i = 0; i < qSize; i++) {
    int left = l[i], right = r[i];

    vector<int> cur(nums.begin() + left, nums.begin() + right + 1);

    bool ret = isArithmetic(cur);
    answer.push_back(ret);
  }

  return answer;
}
```

## 고생한 점
