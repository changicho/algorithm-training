# 2023 KAKAO BLIND RECRUITMENT - 개인정보 수집 유효기간

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150370)

| 난이도 |
| :----: |
|  lv1   |

## 설계

### 시간 복잡도

문자열의 길이는 고정되어있다.

배열 terms의 길이를 N, privacies의 길이를 M이라 하자.

hash map을 이용해 각 약관마다 유효기간을 O(1)의 시간 복잡도로 구할 수 있다.

따라서 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정답 배열에 O(M)의 공간 복잡도를 사용한다.

각 약관의 hash map에 O(N)의 공간 복잡도를 사용한다.

따라서 총 공간 복잡도는 O(N + M)이다.

### hash map & 문자열 변환

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + M)   |  O(N + M)   |

각 달은 28일로 지정되어있으므로, 입력받은 날짜들을 모두 일로 변환한다.

이후 각 약관마다 key와 유효기간을 저장한다. (달 \* 28)

이후 각 개인정보의 유효기간을 계산하고, 현재 날짜와 비교한다.

```cpp
// every month has 28
int convert(string date) {
  string year = {date[0], date[1], date[2], date[3]};
  string month = {date[5], date[6]};
  string day = {date[8], date[9]};

  int count = stoi(year) * 12 * 28 + stoi(month) * 28 + stoi(day);
  return count;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
  vector<int> answer;

  unordered_map<char, int> um;

  int todayDate = convert(today);

  for (string &term : terms) {
    char key = term[0];
    int month = stoi(term.substr(2));

    um[key] = month * 28;
  }

  for (int i = 0; i < privacies.size(); i++) {
    string privacy = privacies[i];
    char key = privacy.back();
    string date = privacy.substr(0, 10);

    if (todayDate >= convert(date) + um[key]) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}
```

## 고생한 점
