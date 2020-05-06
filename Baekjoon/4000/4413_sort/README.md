# 4413. CDVII

[링크](https://www.acmicpc.net/problem/4413)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Unranked |    6.667    |

## 설계

### 시간복잡도

N은 최대 1000까지 주어진다.

각 사람마다 enter와 exit를 시간마다 판별해야하므로 브루트 포스 방법을 사용할 수 있다.

그러나 이 방법을 사용할 경우 시간에 따른 예외 처리가 복잡해진다.

따라서 정렬을 이용해 각 사람, 시간, enter&exit, distance 순으로 정렬한다.

이 경우 NlogN 번으로 정렬을 수행할 수 있고, 정렬된 경우는 순차적으로 비교하면 되므로 최악의 시간복잡도는 NlogN이다.

이는 제한시간 내에 충분하다.

### 입력

입력 데이터에서 만약 exit 한 사람이 존재하는 경우는 시간과 동작이 쌍으로 이루어 지는 경우만 주어진다.

쌍이 없는 경우는 출력하지 않음에 유의한다.

### 정렬

입력받은 line 별로 정렬할 경우 운전자, 시간, enter > exit 임이 보장되므로 하나의 문자열로 생각해 정렬하는 편이 용이하다.

그러나 입력이 공백으로 구분되어있어 line별로 입력받기가 수월하지 않다.

따라서 struct를 이용하고 아래와 같은 방법으로 입력을 받는다.

```cpp
while (cin >> photos[n].lic) {
  cin >> photos[n].h_s >> photos[n].e >> photos[n].d;

  // 시간 입력의 형태는 mm:dd:hh:mm 로 주어지므로 정리해 입력받는다.
  photos[n].h = trim_hour(photos[n].h_s);

  n++;
}
```

그리고 구조체를 다음과 같이 설정한다.

```cpp
struct photo {
  string lic;
  string h_s;
  int h;
  string e;
  int d;

  string toString() { return lic + " " + h_s + " " + e + " " + to_string(d); }
};
```

toString() 메소드를 통해 내부 인자값들을 하나의 line 문자열로 return해준다.

따라서 sort의 compare 함수는 다음과 같이 작성할 수 있다.

```cpp
bool compare(photo a, photo b) { return a.toString() < b.toString(); }
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       4        |

## 고생한 점
