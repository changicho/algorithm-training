# 2997. Minimum Number of Operations to Make Array XOR Equal to K

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 갯수를 N이라 하자.

모든 수를 XOR연산 한 후 K와 다른 비트를 비교해 풀이할 수 있다.

각 숫자의 최대값은 10^5 이하이므로 비트연산에 O(1)의 시간 복잡도가 소요된다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

비트마스크를 이용해 풀이할 경우 O(1)의 공간 복잡도가 필요하다.

### 비트연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     128      |    O(N)     |    O(1)     |

nums의 특정 수의 비트를 바꾸는 데 cost는 1이다.

이 때 모든 수를 XOR 연산하며 K와 비트가 같아질 수 있다.

따라서 미리 XOR 연산을 모두 수행한 뒤의 비트 마스크와 K의 비트 마스크를 비교해 변경할 부분만 변경한다.

두 비스마스크를 문자열로 변환해 다른 부분의 갯수를 센다.

```cpp
string convert(int num) {
  string ret(32, '0');

  for (int i = 0; i < 32; i++) {
    if (num % 2 > 0) {
      ret[i] = '1';
    }
    num /= 2;
  }
  return ret;
}

int getDiff(string &a, string &b) {
  int size = a.size();
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      count++;
    }
  }
  return count;
}

int minOperations(vector<int> &nums, int k) {
  int bit = 0;
  for (int &num : nums) {
    bit ^= num;
  }

  string a = convert(bit), b = convert(k);

  return getDiff(a, b);
}
```

### 비트연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     121      |    O(N)     |    O(1)     |

위 방법에서 두 개의 비트마스크를 비교하는 것이 아닌 처음부터 K에 XOR연산을 수행해 남은 비트를 센다.

이는 XOR 연산 시에 두 수에서 다른 비트만 남기는 특성을 이용한다.

```cpp
int minOperations(vector<int> &nums, int k) {
  int bit = k;
  for (int &num : nums) {
    bit ^= num;
  }

  return __builtin_popcount(bit);
}
```

## 고생한 점
