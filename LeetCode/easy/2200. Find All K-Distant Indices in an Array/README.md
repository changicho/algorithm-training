# 2200. Find All K-Distant Indices in an Array

[링크](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 경우마다 브루트 포스 방법을 이용할 경우, 중복된 경우까지 탐색할 수 있다. 이를 모두 탐색할 경우 O(N \* K)의 시간 복잡도를 사용한다.

투 포인터를 이용해 중복되는 부분을 제거할 수 있다. 이 경우 O(N)의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

브루트 포스 방법에 중복 제거를 위해 hash set을 사용할 경우 O(N)의 공간을 추가로 사용한다.

투 포인터를 사용할 경우 O(1)의 추가 공간을 사용한다.

### 브루트 포스 & 해시

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     184      |  O(N \* K)  |    O(N)     |

각 index를 순회하며 현재 숫자가 key인경우 앞 뒤로 k개의 숫자를 탐색한다.

이 때 중복된 경우를 탐색할 수 있으므로 정답의 후보를 hash set에 저장한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
  int size = nums.size();

  unordered_set<int> indexes;
  vector<int> answer;

  for (int i = 0; i < size; i++) {
    if (nums[i] != key) continue;

    for (int j = max(0, i - k); j < min(size, i + k + 1); j++) {
      indexes.insert(j);
    }
  }

  for (int idx : indexes) {
    answer.push_back(idx);
  }
  sort(answer.begin(), answer.end());
  return answer;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N )    |    O(N)     |

index를 순회하며 현재 수가 key인지 판단한다.

동시에 정답에 넣을 index를 순회하는 변수 j를 함께 둔다.

현재 index에서 앞뒤로 k개의 숫자를 탐색하고자 할 때 j를 이동시키며 정답에 삽입한다.

j는 이전에 마지막으로 탐색했던 index를 알고있으므로 중복된 부분을 건너뛸 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
  int size = nums.size();
  vector<int> answer;
  for (int i = 0, j = 0; i < size; ++i) {
    if (nums[i] != key) continue;

    for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j) {
      answer.push_back(j);
    }
  }

  return answer;
}
```

## 고생한 점
