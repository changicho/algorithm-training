# 2442. Count Number of Distinct Integers After Reverse Operations

[링크](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums 원소의 갯수를 N이라 하자.

해당 값들을 우선 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

원소의 최대 크기는 10^6 까지 이며 이를 뒤집는데 O(1)의 시간 복잡도를 사용한다.

hash set을 이용해 순회하며 유일한 값들만 저장할 수 있다.

이 경우 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     478      |    O(N)     |    O(N)     |

각 수를 순회하며 hash set에 원본값과 reverse한 값을 저장한다.

이후 hash set의 크기를 반환한다.

```cpp
int reverseDigit(int num) {
  int ret = 0;
  while (num > 0) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }
  return ret;
}

int countDistinctIntegers(vector<int>& nums) {
  unordered_set<int> us;

  for (int& num : nums) {
    us.insert(num);
    us.insert(reverseDigit(num));
  }
  return us.size();
}
```

## 고생한 점
