# 2502. Design Memory Allocator

[링크](https://leetcode.com/problems/design-memory-allocator/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 크기를 N이라 하자.

각 과정마다 배열을 직접 탐색하며 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 저장 공간을 사용해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     149      |    O(N)     |    O(N)     |

배열을 직접 만들고 각 과정마다 연산을 구현한다.

```cpp
class Allocator {
 private:
  vector<int> memory;

  int getFirstEmpty(int need) {
    int size = memory.size();
    for (int i = 0; i < size; i++) {
      if (memory[i] != -1) continue;
      int length = 0;
      int start = i;
      while (i < size && memory[i] == -1) {
        length++;
        i++;
      }

      if (length >= need) {
        return start;
      }
    }
    return -1;
  }

 public:
  Allocator(int n) { memory.resize(n, -1); }

  int allocate(int size, int mID) {
    int first = getFirstEmpty(size);
    if (first == -1) return -1;
    for (int i = first; i < first + size; i++) {
      memory[i] = mID;
    }
    return first;
  }

  int free(int mID) {
    int size = memory.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (memory[i] != mID) continue;
      count++;
      memory[i] = -1;
    }
    return count;
  }
};
```

## 고생한 점
