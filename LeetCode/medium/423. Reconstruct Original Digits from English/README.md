# 423. Reconstruct Original Digits from English

[링크](https://leetcode.com/problems/reconstruct-original-digits-from-english/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s의 길이를 L이라 하자.

각 문자를 순회하며 count하고, 이후 각 숫자의 글자를 표현하는데 필요한 만큼 count한다.

이 순회에 O(L)의 시간 복잡도를 사용한다.

이후 각 숫자를 정렬해야한다. 이를 카운팅 정렬을 이용해 수행할 경우 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 알파벳 글자수마다 count를 진행해야하며, 이에 O(1)의 공간 복잡도를 사용한다.

정답으로 문자열을 반환해야한다. 이에 O(L)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      69      |    O(L)     |    O(L)     |

각 알파벳을 구분할 수 있는 문자를 하나씩 뽑는다.

- 0 : z
- 1 : o
- 2 : w
- 3 : r
- 4 : u
- 5 : v
- 6 : x
- 7 : v
- 8 : g
- 9 : i

이후 s를 순회하며 해당 문자들을 count한다.

count한 각 문자의 수만큼 정답에 해당 숫자를 추가한다.

```cpp
string originalDigits(string s) {
  vector<string> words = {"zero", "two",   "four", "six",   "eight",
                          "one",  "three", "five", "seven", "nine"};
  vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
  vector<int> distinctChars = {'z', 'w', 'u', 'x', 'g',
                                'o', 'r', 'f', 'v', 'i'};
  vector<int> counts(26, 0);

  for (char c : s) {
    counts[c - 'a']++;
  }

  string result = "";
  for (int num = 0; num < 10; num++) {
    int count = counts[distinctChars[num] - 'a'];

    for (char &c : words[num]) {
      counts[c - 'a'] -= count;
    }

    while (count--) {
      result += to_string(nums[num]);
    }
  }
  sort(result.begin(), result.end());
  return result;
}
```

## 고생한 점
