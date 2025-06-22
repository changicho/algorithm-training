# 3085. Minimum Deletions to Make String K-Special

[링크](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

각 문자의 빈도를 세는 데 O(N) 시간복잡도를 사용한다.

이후 빈도를 순회하며 빈도의 수의 차이가 K이하가 되기 위해 삭제해야 하는 갯수를 센다. 이에 O(26) = O(1) 시간복잡도를 사용한다.

### 공간 복잡도

빈도를 저장하는데 O(26) = O(1) 공간복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 문자열의 문자 빈도를 센다.

특정 범위(left, right)를 가장 유리하게 설정하기 위해선 시작점이나 끝점을 실제 문자의 빈도로 설정한다.

이후 각 문자의 빈도에 대해 해당 범위에 포함되지 않는 문자의 빈도를 센다. 이때, 범위는 left, left+k이다.

이 때 범위보다 큰 경우는 범위에 맞게 삭제하고, 범위보다 작은 경우는 모든 문자를 삭제함에 유의한다.

```cpp
int calc(int left, int right, int *count) {
  int ret = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] < left) {
      ret += count[i];
    } else if (count[i] > right) {
      ret += count[i] - right;
    }
  }
  return ret;
}

int minimumDeletions(string word, int k) {
  int count[26] = {
      0,
  };

  for (char &c : word) {
    count[c - 'a']++;
  }

  int answer = word.size();
  for (int i = 0; i < 26; i++) {
    if (count[i] == 0) continue;

    int cur = calc(count[i], count[i] + k, count);

    answer = min(answer, cur);
  }
  return answer;
}
```

## 고생한 점
