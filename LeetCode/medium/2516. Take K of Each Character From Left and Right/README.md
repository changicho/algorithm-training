# 2516. Take K of Each Character From Left and Right

[링크](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자. (N <= 10^5)

특정 갯수를 선택한다고 했을 때 가능한지 판단하는 데 O(N)의 시간 복잡도를 사용한다.

이 특정 갯수에 대해 이분탐색을 적용할 수 있으므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

투 포인터를 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

특정 갯수에 대해 가능한지 판단하는데 슬라이딩 윈도우를 사용할 수 있다. 이 경우 O(1)의 공간 복잡도를 사용한다.

이분 탐색에 별도의 공간을 사용하지 않아도 되므로 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |    O(N )    |    O(1)     |

선택 범위를 다음과 같이 나타낼 수 있다.

- 0 ~ left
- right ~ end

여기서 left를 end까지 이동시킨뒤 왼쪽으로 한칸씩 이동시킨다.

이 과정에서 포함되지 않는 글자 수를 줄인다.

이 과정에서 각 알파벳의 갯수가 K개 미만이 될 경우 right를 왼쪽으로 이동시키며 알파벳들을 증가시킨다.

```cpp
int takeCharacters(string s, int k) {
  int length = s.length();
  unordered_map<char, int> count;

  for (char &c : s) {
    count[c]++;
  }

  if (count['a'] < k || count['b'] < k || count['c'] < k) return -1;

  int answer = INT_MAX;
  for (int i = length - 1, j = length - 1; i >= 0; i--) {
    count[s[i]]--;
    while (count[s[i]] < k) {
      count[s[j]]++;
      j--;
    }
    answer = min(answer, i - 1 + length - j);
  }
  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     213      | O(N \* log_2(N)) |    O(1)     |

특정 갯수를 뽑았을 때 각 알파벳이 K개 이상 포함되도록 구성 가능한지 슬라이딩 윈도우를 이용해 판단할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

이를 선택 가능한 모든 갯수에 대해 판단하는데 이분 탐색을 사용할 수 있다.

```cpp
bool isPossible(int count[3], int k) {
  return count[0] >= k && count[1] >= k && count[2] >= k;
}

bool canMakeIt(string &s, int length, int k) {
  int count[3] = {0, 0, 0};
  for (int i = 0; i < length; i++) {
    count[s[i] - 'a']++;
  }
  if (isPossible(count, k)) return true;

  for (int i = 0; i < length; i++) {
    int rI = s.size() - 1 - i;

    count[s[(length - 1) - i] - 'a']--;
    count[s[rI] - 'a']++;

    if (isPossible(count, k)) return true;
  }
  return false;
}

int takeCharacters(string s, int k) {
  int length = s.size();
  int left = 0, right = length + 1;

  int answer = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (canMakeIt(s, mid, k)) {
      // pick left part
      answer = mid;
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
