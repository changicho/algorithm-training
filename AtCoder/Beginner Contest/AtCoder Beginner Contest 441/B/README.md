# B - Two Languages

[링크](https://atcoder.jp/contests/abc441/tasks/abc441_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

타카하시와 아오키의 알파벳 문자열의 길이는 최대 26이다.

단어 배열 길이를 N, 문자열의 합을 L이라 하자.

타카하시와 아오키가 사용 가능한 문자 세트를 비트마스크로 표현하는데 O(1)이 걸린다.

각 문자열을 순회하며 비트마스크로 변환한 뒤 판단하는데 O(L) 시간이 걸린다.

따라서 총 시간 복잡도는 O(N + L)이다.

### 공간 복잡도

비트 마스크에 O(1)의 공간 복잡도를 사용한다.

### 비트연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(N + L)   |    O(1)     |

타카하시, 아오키가 사용 가능한 알파벳을 비트마스크로 표현한다.

현재 단어에 포함된 알파벳을 비트마스크로 표현한 뒤, 타카하시와 아오키가 해당 단어를 만들 수 있는지 비트 연산으로 판단한다.

이는 AND연산을 이용해 가능한 알파벳 쌍이 현재 알파벳 쌍을 모두 포함하는지로 판단한다.

만약 두명 모두 만들 수 있거나 두명 모두 못만드는 경우는 "Unknown"을 답에 추가한다.

그 외의 경우 가능한 인물을 답에 추가한다.

```cpp
vector<string> solution(int n, string& s, int m, string& t, int q, vector<string>& words) {
  vector<string> answer;

  int takahashiBit = 0;
  int aokiBit = 0;

  for (char& c : s) {
    takahashiBit |= (1 << (c - 'a'));
  }
  for (char& c : t) {
    aokiBit |= (1 << (c - 'a'));
  }

  for (string& word : words) {
    int bit = 0;
    for (char& c : word) {
      bit |= (1 << (c - 'a'));
    }

    bool canTakahashi = (takahashiBit & bit) == bit;
    bool canAoki = (aokiBit & bit) == bit;

    if (canTakahashi == canAoki) {
      answer.push_back("Unknown");
    } else if (canTakahashi) {
      answer.push_back("Takahashi");
    } else if (canAoki) {
      answer.push_back("Aoki");
    } else {
      answer.push_back("Unknown");
    }
  }

  return answer;
}
```

## 고생한 점
