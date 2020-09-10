# 17676. [1차] 추석 트래픽

[링크](https://programmers.co.kr/learn/courses/30/lessons/17676)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   1822    |

## 설계

### 시간 복잡도

응답 완료 시간순으로 데이터가 정렬되어 있음에 유의한다.

모든 경우를 비교할 필요 없이, 응답 완료 시간을 기준으로 비교하면 된다.

이는 응답 완료 시간이 a, a+10 인 응답들이 있을 때, a+1 ~ a+9 의 응답 갯수를 비교하는 경우

a+10부터 시작하는 응답갯수와 동일하기 때문이다.

응답의 개수는 최대 2000 개 이다.

이중 반복문으로 푼다고 하면 최악의 경우 시간 복잡도는 O(N^2) 이고 이는 4,000,000 이다.

### 공간 복잡도

시간을 숫자료 변환해 이용하는 경우, 밀리세컨드 단위 까지 전부 숫자로 변환했을 때의 최악의 경우 크기는

```cpp
25 * 3600 * 1000 = 90,000,000
```

이므로 int형으로 충분하다.

### 시간 파싱

각 자리수가 고정되어 있는 경우는 substr를 이용, 그 외 miliseconds의 경우에는 다음과 같이 처리함.

```cpp
vector<int> transform(string line) {
  int from = 0;
  int to = 0;

  string hour = line.substr(11, 2);
  string minute = line.substr(14, 2);
  string second = line.substr(17, 6);

  to = stoi(hour) * 60 * 60 * 1000 + stoi(minute) * 60 * 1000 + stod(second) * 1000;

  string left = line.substr(24);
  string leftSecond = "";

  for (char c : left) {
    if (c >= '0' && c <= '9') {
      leftSecond += c;
    } else if (c == 's') {
      // 자리수를 맞춰주기 위한 0 추가
      for (int i = leftSecond.length(); i < 4; i++) {
        leftSecond += "0";
      }
    }
  }
  from = to - stoi(leftSecond);

  return {from, to};
}
```

## 고생한 점

입력받은 시간이 시작시간이 아닌 응답 완료 시간임에 유의하자.
