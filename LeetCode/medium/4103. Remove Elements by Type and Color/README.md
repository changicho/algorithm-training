# 4103. Remove Elements by Type and Color

[링크](https://leetcode.com/problems/remove-elements-by-type-and-color/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

stack을 사용해 연속된 값들을 관리할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

stack에 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |    O(N)     |    O(N)     |

스택을 이용해 현재 타입과 색상이 직전값과 같은 경우 갯수를 증가시키고, 아닌 경우 새로 스택에 넣는다.

이 때 스택의 top의 갯수가 groupSize의 해당 타입의 갯수인 경우 스택에서 삭제한다.

```cpp
struct Data {
  int t, c, count;
};

bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
  int size = types.size();

  vector<Data> stk;
  for (int i = 0; i < size; i++) {
    int t = types[i], c = colors[i];

    if (!stk.empty() && stk.back().t == t && stk.back().c == c) {
      stk.back().count++;
    } else {
      stk.push_back({t, c, 1});
    }

    if (stk.back().count == groupSize[t]) {
      stk.pop_back();
    }
  }

  if (stk.size() > 0) return false;

  return true;
}
```

## 고생한 점
