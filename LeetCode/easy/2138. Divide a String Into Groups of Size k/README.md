# 2138. Divide a String Into Groups of Size k

[링크](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회하며 k길이의 문자열로 나누는 데 O(N)의 시간이 걸린다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 index를 순회하며 k길이의 문자열로 나누는 완전탐색을 진행한다. 만약 문자열의 길이가 k의 배수가 아니라면, 남은 부분을 채우기 위해 fill 문자를 추가한다.

```cpp
vector<string> divideString(string s, int k, char fill) {
  int size = s.size();

  vector<string> answer;
  for (int i = 0; i < size; i += k) {
    string cur = "";
    for (int j = 0; j < k; j++) {
      if (i + j >= size) {
        cur += fill;
      } else {
        cur += s[i + j];
      }
    }
    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
