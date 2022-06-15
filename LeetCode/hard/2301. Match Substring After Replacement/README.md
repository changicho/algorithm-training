# 2301. Match Substring After Replacement

[링크](https://leetcode.com/problems/match-substring-after-replacement/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

s의 길이를 N, sub의 길이를 M, mappings의 크기를 K이라 하자.

우선 mapping을 순회하며 특정 문자를 다른 문자로 바꿀 수 있는 지 여부를 체크한다. 이에 O(K)의 시간 복잡도를 사용한다.

이후 각 s를 시작점으로 순회하며 해당 문자를 시작점으로 sub를 만들 수 있는지 판단한다.

이에 O(N \* M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* M + K) 이다.

### 공간 복잡도

특정 문자에서 다른 문자로 바꾸는 지 여부를 table에 저장하는데 O(256 \* 256)의 공간복잡도를 사용한다. 따라서 O(1)의 공간 복잡도를 사용한다.

### brute force & table

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     305      | O(N \* M + K) |    O(1)     |

mappings를 순회할 때 앞 문자를 first, 뒤 문자를 second라고 하자.

이를 정리하면 second -> first로 변경할 수 있다.

mappings을 순회하며 변환 테이블을 완성한다.

이후 s의 각 index를 순회하며 각 index를 시작점으로 했을 때 sub를 만들 수 있는지 판단한다.

이를 구현하면 다음과 같다.

```cpp
bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
  bool canChange[256][256] = {
      false,
  };

  for (vector<char>& mapping : mappings) {
    canChange[mapping.back()][mapping.front()] = true;
  }

  int length = s.length();
  for (int i = 0; i <= length - sub.length(); i++) {
    bool flag = true;
    for (int j = 0; j < sub.length(); j++) {
      if (s[i + j] == sub[j] || canChange[s[i + j]][sub[j]]) {
        continue;
      }
      flag = false;
      break;
    }

    if (flag) return true;
  }

  return false;
}
```

## 고생한 점
