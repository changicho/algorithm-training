# 944. Delete Columns to Make Sorted

[링크](https://leetcode.com/problems/delete-columns-to-make-sorted/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 열에 대해 순회할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 행렬을 순회만 할 경우 별도의 공간 복잡도를 필요로 하지 않는다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |  O(R \* C)  |    O(1)     |

입력받은 각 문자열들에 대해서 열대로 순회를 진행한다.

이때 다음행의 좌표가 현재행의 좌표보다 값이 작을 경우 해당 열은 정렬되지 않았으므로 count를 증가시킨다. 이후 다음열로 넘어간다.

이를 모든 열에 대해 반복한다.

```cpp
int minDeletionSize(vector<string>& strs) {
  int answer = 0;

  int rows = strs.size(), cols = strs.front().size();

  for (int x = 0; x < cols; x++) {
    bool isSorted = true;
    for (int y = 0; y < rows - 1; y++) {
      if (strs[y][x] > strs[y + 1][x]) {
        isSorted = false;
        break;
      }
    }

    if (!isSorted) answer++;
  }

  return answer;
}
```

## 고생한 점
