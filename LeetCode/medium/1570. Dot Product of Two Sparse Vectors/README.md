# 1570. Dot Product of Two Sparse Vectors

[링크](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

vector의 원소의 갯수를 N, 그 중 0이 아닌것의 수를 L이라 하자.

각 index별로 순회하며 연산을 수행할 경우 O(N)의 시간 복잡도를 사용한다.

0이 아닌 수에 대해서만 연산을 수행할 경우 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 index별로 순회하며 연산을 수행할 경우 reference만을 이용해 O(1)의 공간 복잡도를 사용할 수 있다.

0이 아닌 수에 대해서만 연산을 수행할 경우 O(L)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     188      |    O(N)     |    O(1)     |

각 SparseVector에 입력받은 vector를 저장하고 이를 모두 순회하며 정답을 구한다.

```cpp
class SparseVector {
 public:
  vector<int> nums;
  SparseVector(vector<int>& nums) { this->nums = nums; }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ret = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      ret += vec.nums[i] * nums[i];
    }

    return ret;
  }
};
```

### trim zero

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     168      |    O(L)     |    O(L)     |

0이 아닌 수의 index, value만 저장하고 이를 이용한다.

곱을 구할 때 두 수중 하나라도 0인 경우는 어차피 결과가 0이므로 무시할 수 있기 때문이다.

따라서 constructor에서 0인 value는 모두 무시한 index, value 쌍을 저장해 사용한다.

```cpp
class SparseVector {
 public:
  unordered_map<int, int> nonZeros;
  SparseVector(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) continue;
      nonZeros[i] = nums[i];
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ret = 0;

    for (auto& it : nonZeros) {
      int key = it.first, value = it.second;

      if (vec.nonZeros.find(key) == vec.nonZeros.end()) continue;
      ret += vec.nonZeros[key] * value;
    }

    return ret;
  }
};
```

## 고생한 점
