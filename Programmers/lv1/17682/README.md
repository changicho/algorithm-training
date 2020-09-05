# 17682. [1차] 다트 게임

[링크](https://programmers.co.kr/learn/courses/30/lessons/17682)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv1   |   4848   |

## 설계

### 시간 복잡도

입력받는 문자열의 길이는 최대 12이다.

이를 순회하며 필요한 부분만 추출하면 되므로, 각 의미하는 형태별로 쪼갠다고 해도 시간 복잡도는 3N 이내이다.

따라서 충분.

### 공간 복잡도

숫자의 크기는 최대 10^3 이므로 int형으로 선언.

### 파싱

각 다트의 결과는 다음과 같이 이루어져 있다.

- 점수
- 제곱
- 옵션

2~4자리의 글자에서 다음 정보들을 추출해야한다.

따라서 총 3번 순회하며 점수, 제곱, 옵션에 대한 값을 추출한다.

이 때 숫자를 추출할 때, 숫자가 0인 경우에 주의한다.

```cpp
struct Score {
  int score;
  int square;
  int option;
};

vector<Score> parse(string dartResult) {
  vector<Score> result = {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}};
  int index = 0, temp = 0;
  bool isNumberCount = false;

  // 숫자 추출
  index = 0;
  for (char c : dartResult) {
    if (c >= '0' && c <= '9') {
      isNumberCount = true;
      temp *= 10;
      temp += c - '0';
    } else {
      if (!isNumberCount) continue;

      result[index].score = temp;
      temp = 0;
      index++;
      isNumberCount = false;
    }
  }

  // 제곱 추출
  index = 0;
  for (char c : dartResult) {
    if (c == 'S') {
      result[index].square = 1;
      index += 1;
    } else if (c == 'D') {
      result[index].square = 2;
      index += 1;
    } else if (c == 'T') {
      result[index].square = 3;
      index += 1;
    }
  }

  // 옵션 추출
  index = -1;
  for (char c : dartResult) {
    if (c == 'S' || c == 'D' || c == 'T') {
      index += 1;
    } else if (c == '*' || c == '#') {
      if (c == '*') {
        result[index].option *= 2;
        if (index - 1 >= 0) result[index - 1].option *= 2;
      } else if (c == '#') {
        result[index].option *= -1;
      }
    }
  }

  return result;
}
```

## 고생한 점
