# 1598. Crawler Log Folder

[링크](https://leetcode.com/problems/crawler-log-folder/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 logs의 크기를 N이라 하자.

logs를 순회하며 각 log에 대해 폴더의 상태를 갱신한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

스택을 사용하지 않고 폴더의 상태를 갱신할 경우 별도의 공간이 필요하지 않다.

### counter

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 폴더의 깊이 상태를 저장할 변수를 선언한다.

이후 logs를 순회하며 각 log에 대해 깊이의 상태를 갱신한다.

```cpp
int minOperations(vector<string>& logs) {
  int count = 0;

  for (string& log : logs) {
    if (log == "../") {
      if (count > 0) {
        count--;
      }
    } else if (log == "./") {
      continue;
    } else {
      count++;
    }
  }

  return count;
}
```

## 고생한 점
