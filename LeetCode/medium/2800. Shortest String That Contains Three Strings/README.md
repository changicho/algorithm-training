# 2800. Shortest String That Contains Three Strings

[링크](https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 최대 길이를 N이라 하자. (N <= 100)

문자열 3개를 합친 길이는 최대 300이며 이를 모든 경우에 대해 탐색할 경우 O(3^300)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

문자열을 합치는 경우의 수에 대해서 탐색을 진행하고, 각 경우마다 최소 문자열을 반환한다.

이 경우 문자열을 조합하는 데 O(N^2)의 시간 복잡도를 사용하며 총 6가지 경우에 대해 탐색한다.

따라서 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

새로운 문자열을 생성하므로 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색 & 문자열 합치기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      70      |   O(N^2)    |    O(N)     |

두 문자열 a, b를 합쳤을 때 최대 겹치는 부분을 찾고 합칠 수 있다.

이에 a+b를 구성하는 데에 a의 suffix, b의 prefix에 대해서 비교를 진행해야 하며 가능한 경우들에 대해 탐색을 진행하므로 O(N^2)의 시간 복잡도를 사용한다.

이후 가능한 조합에 대해서 모두 탐색을 진행할 수 있다.

a,b를 합쳐 최소길이 문자열을 반환하는 merge 함수가 존재할 때 경우의 수는 다음과 같다.

- merge(a, b, c)
- merge(a, c, b)
- merge(b, a, c)
- merge(b, c, a)
- merge(c, a, b)
- merge(c, b, a)

각 경우들을 비교하며 정답을 갱신한다.

```cpp
string merge(string a, string b) {
  if (a.find(b) != -1) return a;
  if (b.find(a) != -1) return b;

  int commonL = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size() && i + j < a.size(); j++) {
      if (a[i + j] != b[j]) {
        break;
      }
      if (i + j == a.size() - 1) commonL = max(commonL, j + 1);
    }
  }

  string ret = a + b.substr(commonL);

  return ret;
}

string minimumString(string a, string b, string c) {
  vector<int> arr = {0, 1, 2};
  string answer = a + b + c;

  vector<string> targets = {a, b, c};
  do {
    string foo = merge(targets[arr[0]], targets[arr[1]]);
    string cur = merge(foo, targets[arr[2]]);

    if (answer.size() > cur.size()) {
      answer = cur;
    } else if (answer.size() == cur.size()) {
      answer = min(answer, cur);
    }
  } while (next_permutation(arr.begin(), arr.end()));

  return answer;
}
```

## 고생한 점
