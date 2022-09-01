# 2384. Largest Palindromic Number

[링크](https://leetcode.com/problems/largest-palindromic-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 num의 길이를 N이라 하자.

그리디 알고리즘을 이용해 큰 수부터 선택해 숫자를 만들어나갈 수 있다.

이 경우 숫자의 갯수들을 세는데 O(N)의 시간 복잡도를, 이를 이용해 정답 문자열을 생성하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

0 ~ 9 의 갯수를 세는데 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(N)     |

num에 들어있는 문자들의 갯수를 센다.

가장 긴 문자열을 정답이며, 해당 길이에서 가장 큰 값을 만들어야 한다.

이를 위해 그리디 알고리즘을 이용할 수 있다.

우선 팰린드롬을 생성하기 위해선 갯수가 홀수인 숫자는 최대 한개까지만 존재할 수 있다.

따라서 갯수가 홀수인 숫자들 중 가장 큰 수를 선택하고, 그 외의 수들은 가능한 가장 큰 짝수개만큼만 정답에 추가한다.

이후 정답의 절반을 남은 숫자들 중 큰수부터 차례로 채우고, 만약 홀수개의 숫자가 있으면 가운데를 이로 채운다.

나머지는 앞에서부터 반대로 채워나간다.

이를 구현하면 다음과 같다.

```cpp
string getNum(vector<int> &keys, vector<int> &counts) {
  int odd = -1;
  for (int &key : keys) {
    if (counts[key] % 2 == 1) {
      odd = key;
      break;
    }
  }

  string half = "";
  string answer = "";
  for (int &key : keys) {
    if (half.length() == 0 && key == 0) break;

    half += string(counts[key] / 2, key + '0');
  }
  answer += half;
  if (odd != -1) {
    answer.push_back(odd + '0');
  }
  reverse(half.begin(), half.end());
  answer += half;

  if (answer.length() == 0) return "0";
  return answer;
}

string largestPalindromic(string num) {
  vector<int> counts(10, 0);

  for (char &c : num) {
    counts[c - '0']++;
  }

  bool oddFound = false;
  vector<int> keys;
  for (int key = 9; key >= 0; key--) {
    if (counts[key] % 2 == 0) {
      keys.push_back(key);
    } else {
      if (oddFound) {
        counts[key]--;
      } else {
        oddFound = true;
      }
      keys.push_back(key);
    }
  }

  string answer = getNum(keys, counts);
  return answer;
}
```

## 고생한 점
