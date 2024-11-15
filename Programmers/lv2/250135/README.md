# 250135. [PCCP 기출문제] 3번 / 아날로그 시계

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/250135)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

입력받은 두 시간의 차를 N이라 하자.

각 시간별로 시, 분, 초의 각도를 계산해 구할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 경우마다 변환한 값에 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

각 시, 분, 초에 대해서 각도를 구할 수 있다.

현재 시간과 현재 시간 1초 전의 시간에 대해서 각도를 각각 구하고 다음을 비교한다.

- 분침을 초침이 넘어가는 경우
- 시침을 초침이 넘어가는 경우

직전 각도와 현재 각도값의 대소 관계가 역전되는 경우를 찾는다.

이 때 현재 각도에서 시침, 분침, 초침이 같은 경우는 중복되서 울리는 경우이므로 1번만 카운트한다.

이 세가지가 모두 겹치는 경우는 정오만이다.

```cpp
int convertToSec(int h, int m, int s) { return h * 60 * 60 + m * 60 + s; }

vector<int> split(int seconds) {
  int h = seconds / (60 * 60);
  int m = (seconds % (60 * 60)) / 60;
  int s = seconds % 60;

  return {h, m, s};
}

vector<double> getAngles(vector<int> time) {
  int h = time[0], m = time[1], s = time[2];

  double hA = double(h % 12) * 30 + double(m) / 2 + double(s) / 120;
  double mA = m * 6 + (double)s / 12;
  double sA = s * 6;

  return {hA, mA, sA};
}

int isMatch(int second) {
  int ret = 0;

  vector<int> before = split(second - 1);
  vector<int> cur = split(second);

  vector<double> beforeA = getAngles(before);
  vector<double> curA = getAngles(cur);

  if (curA[2] == 0) {
    if (beforeA[0] > beforeA[2] && curA[0] <= 360.0) ret++;
    if (beforeA[1] > beforeA[2] && curA[1] <= 360.0) ret++;
  } else {
    if (beforeA[0] > beforeA[2] && curA[0] <= curA[2]) ret++;
    if (beforeA[1] > beforeA[2] && curA[1] <= curA[2]) ret++;
  }

  if (curA[0] == curA[1] && curA[1] == curA[2]) {
    ret--;
  }

  return ret;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
  int startTime = convertToSec(h1, m1, s1);
  int endTime = convertToSec(h2, m2, s2);

  int answer = 0;

  if (startTime == 0 || startTime == 12 * 60 * 60) answer++;
  for (int time = startTime + 1; time <= endTime; time++) {
    int ret = isMatch(time);

    answer += ret;
  }

  return answer;
}
```

## 고생한 점
