# 418. Sentence Screen Fitting

[링크](https://leetcode.com/problems/sentence-screen-fitting/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어의 개수를 N, 행의 길이를 R, 열의 길이를 C라고 하자.

각 행마다 단어를 붙여가며 실제 몇번 사이클을 도는 지 체크할 수 있다.

한 행에서 단어들의 사이클을 N번 수행하는 것이 아닌 미리 계산해 한번에 이동할 수 있다.

각 경우마다 사이클을 돌릴 경우 최악의 경우 결국 자리수를 전부 세므로 시간복잡도는 O(R \* C)이다.

또는 각 단어로 행을 처음 시작할 때 채울 수 있는 총 개수를 미리 세놔서 문제를 풀이할 수 있다.

이 경우 각 단어에 대해 한 행에 최대 몇번 나타날 수 있는지를 count한다.

이 경우 각 단어와 행을 한번씩 순회하며, 단어의 개수가 더 작으므로 시간 복잡도는 O(R)이다.

### 공간 복잡도

직접 브루트포스로 카운팅을 수행할 경우 상수만큼의 공간이 필요하다. O(1)이다.

단어에 대한 카운팅을 수행할 경우 각 단어만큼의 공간이 필요하다. 따라서 공간 복잡도는 O(N)이다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |  O(R \* C)  |    O(1)     |

각 행을 순회하며 단어들을 순차적으로 채워나간다.

이 때 단어를 한바퀴 전부 돌 수 있는경우에 대해 미리 점검하고, 이후 남은 단어들을 순차적으로 채워나간다.

```cpp
int wordsTyping(vector<string>& sentence, int rows, int cols) {
  int lineCount = 0;
  int lineLength = 0;
  int answer = 0;
  int i = 0;

  int oneSentenceLineLength = 0;
  for (string& word : sentence) {
    oneSentenceLineLength += word.length() + 1;
  }
  oneSentenceLineLength -= 1;

  while (lineCount < rows) {
    // 사이클 단위로 채워넣기
    if ((cols - lineLength) / (oneSentenceLineLength + 1) > 0) {
      int repeat = (cols - lineLength) / (oneSentenceLineLength + 1);
      lineLength += (oneSentenceLineLength + 1) * repeat;
      answer += repeat;

      if (lineLength == cols) {
        lineLength = 0;
        lineCount += 1;
      }
      continue;
    }
    // 각 단어별로 채워넣기
    if (lineLength + sentence[i].length() <= cols) {
      lineLength += sentence[i].length();
      i += 1;

      if (i == sentence.size()) {
        i = 0;
        answer += 1;
      }
      if (lineLength < cols) {
        lineLength += 1;
      }
      if (lineLength == cols) {
        lineLength = 0;
        lineCount += 1;
      }
      continue;
    }

    lineLength = 0;
    lineCount += 1;
  }

  return answer;
}
```

### 메모이제이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(R)     |    O(R)     |

각 행에 대해서, 어떤 단어로 시작했을 때 한줄을 최대 몇개의 단어로 채울 수 있는지를 미리 계산해놓는다.

이후 현재 행에 대해서 특정 단어로 시작하는 경우 이전에 계산해 놓은 결과를 토대로 정답을 갱신한다.

이는 단어의 개수가 최대 100개 미만이므로 가능하다.

각 단어별로 카운트 배열을 채워넣는데 걸리는 시간 복잡도는 O(N \* C)이다.

이후 행에대해 반복하는데 걸리는 시간 복잡도는 O(R)이다.

이후 채울 수 있는 단어들의 수를 모두 센 뒤에 이 값을 단어의 개수로 나눈 몫이 정답이다.

(단어들을 완전하게 순회한 횟수)

```cpp
int wordsTyping(vector<string>& sentence, int rows, int cols) {
  int size = sentence.size();
  vector<int> counts(size, 0);

  int oneSentenceLineLength = 0;
  for (string& word : sentence) {
    oneSentenceLineLength += word.length() + 1;
  }

  for (int startIdx = 0; startIdx < size; startIdx++) {
    int count = 0, length = 0;
    int wordIdx = startIdx;
    while (length + sentence[wordIdx].length() <= cols) {
      // fill by one cycle
      if (length + oneSentenceLineLength <= cols) {
        int repeat = (cols - length) / oneSentenceLineLength;
        length += oneSentenceLineLength * repeat;

        count += repeat * size;
        continue;
      }

      length += sentence[wordIdx].length() + 1;
      count++;
      wordIdx = (wordIdx + 1) % size;
    }

    counts[startIdx] = count;
  }

  int totalCount = 0;
  for (int row = 0; row < rows; row++) {
    int start = totalCount % size;

    totalCount += counts[start];
  }

  return totalCount / size;
}
```

## 고생한 점
