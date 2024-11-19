# 1652. Defuse the Bomb

[링크](https://leetcode.com/problems/defuse-the-bomb/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 범위를 K라 하자.

완전 탐색을 이용할 경우 O(N * K)의 시간 복잡도가 필요하다.

prefix sum을 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도가 필요하다.

prefix sum에 O(N)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

미리 0부터 i까지의 합을 구한 배열을 생성한다.

각 index별로 더해야 하는 구간을 구한다.

이후 각 구간의 합을 구한다.

```cpp
vector<int> decrypt(vector<int>& code, int k) {
  int size = code.size();

  int sum = 0;
  vector<int> prefix(size + 1);

  for (int i = 0; i < size; i++) {
    prefix[i + 1] = prefix[i] + code[i];
  }

  vector<int> answer(size);
  for (int i = 0; i < size; i++) {
    int cur = 0;

    int left = 0, right = 0;
    if (k > 0) {
      // i+1 ~ i+k
      left = (i + 1) % size, right = (i + k) % size;
    } else if (k < 0) {
      // i-k ~ i-1
      left = (i - abs(k) + size) % size, right = (i - 1 + size) % size;
    } else {
      answer[i] = 0;
      continue;
    }

    if (left < right) {
      cur = prefix[right + 1] - prefix[left];
    } else if (left > right) {
      cur = prefix[right + 1] + prefix[size] - prefix[left];
    } else {
      cur = code[left];
    }

    answer[i] = cur;
  }
  return answer;
}
```

## 고생한 점
