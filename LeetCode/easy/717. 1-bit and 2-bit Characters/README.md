# 717. 1-bit and 2-bit Characters

[링크](https://leetcode.com/problems/1-bit-and-2-bit-characters/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회에 O(N) 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1) 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

왼쪽부터 순회하며 현재 비트가 0인 경우 1칸, 1인 경우 2칸 이동한다.

이후 맨 마지막 index 이후까지 도달했는지 확인한다.

```cpp
bool isOneBitCharacter(vector<int>& bits) {
  int size = bits.size();
  int i = 0;

  while (i < size - 1) {
    if (bits[i] == 0) {
      i++;
    } else {
      i += 2;
    }
  }

  return i == size - 1;
}
```

## 고생한 점
