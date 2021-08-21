# 280. Wiggle Sort

[링크](https://leetcode.com/problems/wiggle-sort/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

오름차순 정렬을 수행하고 이후 one pass를 통해 주어진 조건대로 배열을 정렬할 수 있다.

이 경우 시간 복잡도는 O(N \* log_2(N))이다.

혹은 한번의 순회를 통해 원하는 대로 greedy하게 정렬할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 배열을 생성하는 경우 O(N)의 공간 복잡도가 필요하다.

그 외에 swap을 이용하는 경우 O(1)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      12      | O(N \* log_2(N)) |    O(1)     |

오름차순으로 숫자를 정렬한다.

다음과 같이 숫자가 정렬되어 있다고 가정하자.

```javascript
// a < b < c < d
[a, b, c, d];
```

이 경우 b는 a보다 크고 c보다 작음이 만족한다.

따라서 다음과 같이 순서를 변경할 경우 문제 의도에 일치한다.

```javascript
// a < b < c < d
[a, c, b, d];
```

이 방법을 이용해 2번째 원소부터 i, i+1번째 끼리 swap한다. (2칸씩 이동)

```cpp
void wiggleSort(vector<int>& nums) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  for (int i = 1; i < size - 1; i += 2) {
    swap(nums[i], nums[i + 1]);
  }
}
```

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

숫자를 정렬하지 않고 각 index들을 순회하며 문제 조건에 맞게 정렬한다.

이는 각 숫자의 대소관계가 인접한 양쪽의 숫자에 대한 대소관계만 만족하면 되기 때문이다.

이 때 직전 index의 대소관계가 완료된 상태에서 현재 index와 index+1번째를 swap했을 때 대소관계가 깨지지 않는 이유는, 현재 index, index + 1번째를 swap해야 하는 경우는 직전 대소관계에 영향이 가지 않는 상황에서만 swap이 가능하기 때문이다.

```cpp
void wiggleSort(vector<int>& nums) {
  int size = nums.size();

  for (int i = 0; i < size - 1; i++) {
    bool rightSmall = (i % 2 == 0 && nums[i] > nums[i + 1]);
    bool rightBig = (i % 2 == 1 && nums[i] < nums[i + 1]);

    if (rightSmall || rightBig) {
      swap(nums[i], nums[i + 1]);
    }
  }
}
```

## 고생한 점
