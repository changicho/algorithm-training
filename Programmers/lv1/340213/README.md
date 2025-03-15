# [PCCP 기출문제] 1번 / 동영상 재생기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/340213)

| 난이도 |
| :----: |
|  LV1   |

## 설계

### 시간 복잡도

배열 commands의 크기를 N이라 하자.

순회를 이용해 각 명령어별로 시간을 찾을 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

입력받은 숫자들을 변환한 뒤 연산을 수행한다.

이 때 시간 값의 범위가 존재함에 유의한다.

오프닝 진행중인 시간에 도달한 경우 항상 끝나는 지점으로 이동함에 유의한다.

```cpp
int convert(string &time) {
  int s = (time[3] - '0') * 10 + (time[4] - '0');
  int m = (time[0] - '0') * 10 + (time[1] - '0');

  return m * 60 + s;
}

string convertToS(int time) {
  string ret = "";
  int m = time / 60;
  int s = time % 60;

  if (m < 10) ret += '0';
  ret += to_string(m);
  ret += ':';
  if (s < 10) ret += '0';
  ret += to_string(s);
  return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
  int size = convert(video_len);
  int cur = convert(pos);

  int opS = convert(op_start);
  int opE = convert(op_end);

  if (opS <= cur && cur <= opE) {
    cur = opE;
  }
  for (string &command : commands) {
    if (command == "prev") {
      cur = max(cur - 10, 0);
    } else if (command == "next") {
      cur = min(size, cur + 10);
    }

    if (opS <= cur && cur <= opE) {
      cur = opE;
    }
  }

  return convertToS(cur);
}
```

## 고생한 점
