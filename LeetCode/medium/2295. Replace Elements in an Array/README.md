# 2295. Replace Elements in an Array

[링크](https://leetcode.com/contest/weekly-contest-296/problems/replace-elements-in-an-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, operations의 크기를 M이라 하자.

nums를 순회하며 각 값마다의 index를 저장하고, 이후 operation을 순회하며 값을 변경, 다시 index를 저장하는 과정을 계속한다.

이 경우 두 배열의 순회에 O(N + M)의 시간 복잡도를 사용한다.

index를 hash map, 배열에 저장할 경우 O(1)의 시간 복잡도로 접근이 가능하다.

### 공간 복잡도

hash map, 배열을 사용할 경우 O(10^6)의 공간 복잡도를 사용한다.

이는 O(1)이다.

### index table

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     439      |  O(N + M)   |    O(N)     |

num의 값의 범위는 1 ~ 10^6 까지이다. 이는 매우 크지 않으므로 배열로 key, value를 관리해도 된다.

nums를 순선대로 순회하며 각 값이 나타나는 index를 저장한다.

이는 절대 중복되지 않음이 보장되며, operation을 수행해도 동일하다.

이 순회 후 operation을 순회하며 값을 바꿔나간다. 이때 바뀐 값의 index또한 갱신한다.

```cpp
int idxs[1000001] = {
    0,
};

vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    idxs[nums[i]] = i;
  }

  for (vector<int>& o : operations) {
    int first = o[0], second = o[1];
    int idx1 = idxs[first];

    nums[idx1] = second;
    idxs[first] = 0;
    idxs[second] = idx1;
  }

  return nums;
}
```

## 고생한 점
