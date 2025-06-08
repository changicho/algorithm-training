# 3170. Lexicographically Minimum String After Removing Stars

[링크](https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회하며 가장 작은 문자를 매번 찾을 경우 O(N^2)의 시간 복잡도를 가지게 된다.

이는 제한시간 내에 불가능하다.

각 경우마다 문자의 index를 저장후 가장 작은 문자를 찾는 경우 O(26)으로 해결할 수 있다.

이 경우 O(N)의 시간 복잡도를 가지게 된다.

### 공간 복잡도

정답 문자열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      51      |    O(N)     |    O(N)     |

*을 마주했을 때 가장 작은 문자를 제거할 때 문자열 우선순위가 가장 낮도록 하기 위해선 가장 오른쪽에 있는 문자를 제거해야 한다.

따라서 각 문자마다 index를 저장 후 *을 만났을 때 가장 작은 문자를 제거하는 방식으로 구현한다.

이 때 가장 작은 문자를 판단하는 데 O(26)의 시간 복잡도를 가지게 된다.

```cpp
string clearStars(string s) {
  int size = s.size();

  vector<bool> deleted(size, false);
  vector<stack<int>> indexes(26);

  for (int i = 0; i < size; i++) {
    if (s[i] == '*') {
      int target = -1;
      for (int c = 0; c < 26; c++) {
        if (indexes[c].empty()) continue;

        target = indexes[c].top();
        indexes[c].pop();
        break;
      }

      if (target != -1) {
        deleted[target] = true;
      }

    } else {
      indexes[s[i] - 'a'].push(i);
    }
  }

  string answer = "";
  for (int i = 0; i < size; i++) {
    if (deleted[i] || s[i] == '*') continue;
    answer += s[i];
  }
  return answer;
}
```

## 고생한 점
