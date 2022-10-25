# 1239. Maximum Length of a Concatenated String with Unique Characters

[링크](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자. 이는 최대 16까지이다.

arr에 담겨있는 글자의 최대 길이는 26 이다.

arr에 있는 단어들의 조합들에 대해 모두 탐색할 경우 O(2^N) 의 시간 복잡도를 사용한다.

내부 글자들의 중복을 파악하는데 O(1)의 시간 복잡도로 판단 가능하다.

따라서 총시간 복잡도는 O(2^N)이다.

### 공간 복잡도

DFS로 모든 경우를 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색 & 비트마스킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(2^N)    |    O(N)     |

각 단어들을 포함하고, 포함하지 않는 경우에 대해 모두 탐색해보고 이 때의 최대 글자 갯수를 정답으로 갱신한다.

각 단어마다 중복된 글자가 존재하는 경우 해당 단어는 정답의 경우에 포함될 수 없다.

또한 글자의 종류는 최대 26가지 이므로 비트마스킹으로 이를 표현 가능하다.

각 경우마다 현재 사용하는 글자의 종류와 단어를 비교 후 중복되는 경우가 있는지 판단하고, 해당 단어가 유효한지 판단 후 탐색을 이어나간다.

이를 구현하면 다음과 같다.

```cpp
class Solution {
 private:
  int answer = 0;

  int getLength(int bit) {
    int length = 0;
    while (bit > 0) {
      length += bit % 2;
      bit /= 2;
    }
    return length;
  }

  int convertBit(string &word) {
    int bit = 0;
    for (char &c : word) {
      int cur = (1 << (c - 'a'));
      if ((bit & cur) > 0) return -1;
      bit |= cur;
    }
    return bit;
  }

  void recursive(int index, vector<string> &arr, int bit) {
    int size = arr.size();

    if (index == size) {
      answer = max(answer, getLength(bit));

      return;
    }

    recursive(index + 1, arr, bit);
    int converted = convertBit(arr[index]);
    if (converted == -1) return;
    if (bit & converted) return;
    bit |= converted;
    recursive(index + 1, arr, bit);
  }

 public:
  int maxLength(vector<string> &arr) {
    recursive(0, arr, 0);

    return answer;
  }
};
```

## 고생한 점
