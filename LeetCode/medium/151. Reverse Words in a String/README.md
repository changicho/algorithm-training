# 151. Reverse Words in a String

[링크](https://leetcode.com/problems/reverse-words-in-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

한번 순회를 하며 단어와 공백을 제거하는 과정을 모두 수행해야 한다.

이 경우 outer 시간 복잡도는 O(N)이다.

이후 내부에서 뒤집는 과정을 수행해야 하며 이는 단어 vector를 뒤집거나, 단어를 찾을 때마다 정답 문자열을 새로 만드는 방법으로 가능하다.

이 연산에 들어가는 시간 복잡도는 O(N)이다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

vector를 사용하는 경우 문자열 내부의 단어만큼의 공간이 필요하다.

결과적으로 문자열의 길이 만큼의 추가 공간이 필요하다.

정답으로 새로운 문자열을 반환하는데 이 문자열의 길이는 N까지 일 수 있으므로 공간 복잡도는 O(N)이다.

### vector 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

문자열의 문자를 순회하며 단어들을 추출한다.

이 단어들을 vector에 집어넣고 뒤집은 뒤 새로운 문자열을 만든다.

이 때 새로운 문자열을 만들 때 사이마다 공백을 삽입해준다.

문자열에서 맨 마지막 글자를 제거하는 방법은 다음 두가지이다.

```cpp
str.erase(str.length() - 1);
str.pop_back();
```

문자열에서 단어를 추출할 때 직접 순회해도 되지만 sstream을 이용해서도 가능하다.

```cpp
std::istringstream iss(s);
string word;

while (iss >> word) {
  // do something with word
}
```

```cpp
string reverseWords(string s) {
  vector<string> words;

  string temp = "";
  for (char c : s) {
    if (c == ' ') {
      if (temp != "") words.push_back(temp);
      temp = "";
      continue;
    }

    temp += c;
  }
  if (temp != "") words.push_back(temp);

  reverse(words.begin(), words.end());

  string answer = "";
  for (string word : words) {
    answer += word + " ";
  }
  // answer.erase(answer.length() - 1);
  answer.pop_back();

  return answer;
}
```

### reverse

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

문자열을 순회할 때마다 단어를 만들고, 이를 정답 문자열에 앞에 붙이는 방식으로 정답 문자열을 만들 수 있다.

```cpp
string reverseWords(string s) {
  string answer = "";
  string temp = "";
  for (char c : s) {
    if (c == ' ') {
      if (temp != "") {
        answer.insert(0, temp + ' ');
      }
      temp = "";
      continue;
    }

    temp += c;
  }
  if (temp != "") {
    answer.insert(0, temp + ' ');
  }

  answer.pop_back();
  return answer;
}
```

## 고생한 점
