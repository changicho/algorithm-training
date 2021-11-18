# 68. Text Justification

[링크](https://leetcode.com/problems/text-justification/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

words의 개수를 N, maxWidth 값을 M이라 하자.

words를 하나하나 순회하며 한줄에 넣을 수 있는 만큼 넣고, 초과할 경우 남는 부분은 space로 채워넣는다.

외부에서 words를 순회 하는 데 O(N)의 시간 복잡도가 소요되며, 내부적으로 space를 채우는 데 최대 O(M)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

최악의 경우 정답을 생성하는 데 M의 길이를 가진 N개의 문자열이 나올 수 있다.

따라서 O(N \* M)의 공간 복잡도를 사용한다.

현재 줄에 들어갈 단어들을 모아두기 위해 vector를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N \* M)  |  O(N \* M)  |

단어를 순회하며 현재 line에 삽입할 단어들을 vector에 저장한다.

현재 단어와 vector의 단어들로 line을 만들 때 maxWidth를 넘어설 경우 vector의 단어들을 line으로 변환한 후 vector를 비운다.

line으로 변환할 때 다음과 같이 구현할 수 있다.

남은 space를 remain이라 하자. 이 remain을 다음과 같이 분배해야한다.

- 모든 단어 사이에 균등하게 들어갈 부분
- 특정 단어 사이에 (왼쪽부터) 추가적으로 들어갈 부분

이는 vector의 단어의 개수 - 1 만큼 나눈값과 나머지 값으로 구할 수 있다.
(단어의 개수가 1인 경우는 0으로 나눌 수 없으므로 예외처리한다)

이를 이용해 각 line들을 구하고, 맨 마지막 줄의 경우 다 한줄로 만든 뒤 남는 공간에 space를 채워넣는다.

```cpp
vector<string> fullJustify(vector<string> &words, int maxWidth) {
  vector<string> answer;

  vector<string> temp; // line에 넣을 단어들을 임시 저장하는 vector
  int wordLengthSum = 0; // 현재 temp에 들어간 단어들의 길이 합
  for (string &word : words) {
    // can push current word
    if (wordLengthSum + temp.size() + word.length() <= maxWidth) {
      temp.push_back(word);
      wordLengthSum += word.size();
      continue;
    }

    int size = temp.size(), remain = maxWidth - wordLengthSum;
    int space = 1, extra = 0;
    if (size != 1) {
      space = remain / (size - 1);
      extra = remain % (size - 1);
    }

    string line = "";
    for (string &word : temp) {
      line += word + string(space, ' ');

      if (extra > 0) {
        extra--;
        line += " ";
      }
    }

    // trim line
    if (line.length() > maxWidth) line.erase(maxWidth, line.length());
    line += string(maxWidth - line.length(), ' ');

    answer.push_back(line);

    // clear temp vector
    temp = {word};
    wordLengthSum = word.length();
  }

  // if there are words not included in answer
  if (temp.size() > 0) {
    string line = "";
    for (string &word : temp) {
      line += word + " ";
    }

    if (line.length() > maxWidth) line.erase(maxWidth, line.length());
    line += string(maxWidth - line.length(), ' ');

    answer.push_back(line);
  }

  return answer;
}
```

## 고생한 점

단어들 사이에 space를 어떻게 채울 지에 대한 구현이 어려웠다. (나누기, 나머지 연산을 같이 사용해야 하는 줄 알아채기 어려움)

맨 마지막 줄에 대한 예외 처리를 고려해야 한다.
