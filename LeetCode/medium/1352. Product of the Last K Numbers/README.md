# 1352. Product of the Last K Numbers

[링크](https://leetcode.com/problems/product-of-the-last-k-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

저장되는 수를 N이라 하자.

각 경우마다 직접 곱을 구할 경우 O(K)의 시간 복잡도가 필요하다.

prefix sum을 이용해 O(1)의 시간 복잡도로 구할 수 있다.

### 공간 복잡도

각 수를 저장하는데 최대 O(N)의 공간 복잡도가 필요하다.

각 수에 대한 prefix sum을 저장하는데 O(N)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      30      |    O(1)     |    O(N)     |

prefix sum을 이용해 각 index마다의 곱을 저장할 수 있다.

이 경우 0이 들어오는 경우 이후 모든 곱들이 0이 되므로 값이 오염된다.

여기서 뒤에서 k개의 값의 곱만 구하면 되므로 중간에 0이 들어가는 경우 이전 값들은 모두 무시해도 된다.

따라서 0이 들어오는 경우 prefix sum을 초기화한다.

이후 getProduct의 경우 prefix sum을 이용해 구할 수 있다.

이 때 초기화 할 때 전체 크기또한 초기화 해야함에 유의한다.

```cpp
class ProductOfNumbers {
 private:
  vector<int> prefix;
  int size = 0;

 public:
  ProductOfNumbers() {
    prefix.push_back(1);
    size = 0;
  }

  void add(int num) {
    if (num == 0) {
      prefix = {1};
      size = 0;
    } else {
      prefix.push_back(prefix.back() * num);
      size++;
    }
  }

  int getProduct(int k) {
    if (k > size) return 0;

    return prefix[size] / prefix[size - k];
  }
};
```

## 고생한 점
