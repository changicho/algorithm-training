# 3152. Special Array II

[링크](https://leetcode.com/problems/special-array-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, queries의 크기를 Q라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* Q)이므로 제한시간 내에 불가능하다.

prefix sum을 이용할 경우 O(N + Q)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도가 필요하다.

정답 배열에 O(Q)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + Q)   |  O(N + Q)   |

연이은 숫자의 parity가 다른지 같은지를 true, false로 나타낸다.

이후 해당 값에 대해 prefix sum을 구한다.

각 쿼리마다 해당 구간의 prefix sum을 이용해 구간의 값의 합이 (구간의 길이 - 1)인지 판별한다.

```cpp
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
  int size = nums.size();

  vector<int> prefix(size + 1);
  prefix[1] = 1;
  for (int i = 1; i < size; i++) {
    prefix[i] = prefix[i - 1] + ((nums[i] % 2) != (nums[i - 1] % 2));
  }

  vector<bool> answer;
  for (vector<int>& q : queries) {
    int left = q[0], right = q[1];
    int len = right - left + 1;

    int cur = prefix[right] - prefix[left];

    answer.push_back(cur == (len - 1));
  }
  return answer;
}
```

## 고생한 점
