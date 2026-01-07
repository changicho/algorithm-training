# 370. Range Addition

[링크](https://leetcode.com/problems/range-addition/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 갯수를 Q라 하자.

직접 모든 경우를 수행할 경우 O(N \* Q) 의 시간 복잡도가 소요된다. 이는 제한시간 내에 불가능하다.

index마다 값의 변화를 기록한 diff array를 사용할 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

변화를 기록할 배열을 하나 더 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### diff array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + Q)   |    O(N)     |

각 쿼리에 대해 변화의 시작점과 끝점에 대한 diff array를 만든다.

이후 누적합을 구해 최종 배열을 만든다.

```cpp
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
  vector<int> answer(length + 1, 0);

  for (vector<int>& u : updates) {
    int left = u[0], right = u[1], diff = u[2];

    answer[left] += diff;
    answer[right + 1] -= diff;
  }

  // remove the extra element
  answer.pop_back();
  int cur = 0;
  for (int i = 0; i < length; i++) {
    cur += answer[i];

    answer[i] = cur;
  }
  return answer;
}
```

## 고생한 점
