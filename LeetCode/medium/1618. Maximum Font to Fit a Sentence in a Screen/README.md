# 1618. Maximum Font to Fit a Sentence in a Screen

[링크](https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

text의 길이를 L, fonts의 크기를 N이라 하자.

fontSize에 따라서 wrapping이 가능한지 여부는 선형 관계이다. 따라서 이분 탐색으로 O(log_2(N))의 시간 복잡도로 탐색이 가능하다.

주어진 width, height로 wrapping이 가능한지 판단은 text를 순회해 풀이할 수 있다. 이 경우 O(L)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(L \* log_2(N))이다.

### 공간 복잡도

이분 탐색에 constant space를 사용하므로 공간 복잡도는 O(1)이다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     137      | O(L \* log_2(N)) |    O(1)     |

주어진 데이터들과 특정 fontSize에 대해서 wrapping이 가능한지 여부는 다음과 같이 판단할 수 있다.

- fontSize에 따라 height는 고정값이 나오므로 주어진 h와 비교
- fontSize와 각 char에 따른 width값의 총합 비교

이는 text는 한줄임이 보장되기 때문이다. 또한 영어 소문자로만 이루어져있다.

```cpp
bool isValid(string& text, int w, int h, int fontSize, FontInfo& fontInfo) {
  int curHeight = fontInfo.getHeight(fontSize);
  if (curHeight > h) return false;

  int curWidth = 0;
  for (char& c : text) {
    curWidth += fontInfo.getWidth(fontSize, c);
  }

  return curWidth <= w;
}
```

이후 주어진 배열 (오름차순 정렬되어있는)의 index에 대해서 이분탐색으로 가능한 최대값을 구한다.

```cpp
int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
  int size = fonts.size();

  int answer = -1;
  int left = 0, right = size;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isValid(text, w, h, fonts[mid], fontInfo)) {
      // pick right part
      answer = fonts[mid];
      left = mid + 1;
    } else {
      // pick left part
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
