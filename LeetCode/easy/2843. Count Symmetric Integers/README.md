# 2843. Count Symmetric Integers

[링크](https://leetcode.com/problems/count-symmetric-integers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 low, high의 최대 값을 N이라 하자.

각 숫자에 대해 판별하는데 O(log_10(N))의 시간 복잡도를 사용한다.

이를 모든 수에 완전 탐색으로 구할 경우 O(N \* log_10(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

숫자를 문자열로 변환할 경우 O(log_10(N))의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도  |
| :----------: | :---------------: | :----------: |
|     154      | O(N \* log_10(N)) | O(log_10(N)) |

low ~ high까지의 숫자에 대해서 모두 symmetric 한지 판별한다.

```cpp
bool isSymmetric(int number) {
  string num = to_string(number);
  int size = num.size();
  if (size % 2 == 1) return false;

  int left = 0, right = 0;
  for (int i = 0; i < size / 2; i++) {
    left += num[i];
    right += num[size / 2 + i];
  }
  return left == right;
}

int countSymmetricIntegers(int low, int high) {
  int count = 0;
  for (int i = low; i <= high; i++) {
    if (isSymmetric(i)) count++;
  }
  return count;
}
```

### 완전 탐색 (계산 최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

```cpp
bool isSymmetric(int &number) {
  if (number < 100 && number % 11 == 0) {
    return true;
  }
  if (1000 <= number && number < 10000) {
    int left = number / 1000 + (number % 1000) / 100;
    int right = (number % 100) / 10 + number % 10;

    if (left == right) {
      return true;
    }
  }
  return false;
}

int countSymmetricIntegers(int low, int high) {
  int count = 0;
  for (int i = low; i <= high; i++) {
    if (isSymmetric(i)) count++;
  }
  return count;
}
```

## 고생한 점
