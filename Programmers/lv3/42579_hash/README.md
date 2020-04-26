# 42579. 베스트엘범

[링크](https://programmers.co.kr/learn/courses/30/lessons/42579)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv3   |             |

## 설계

### 자료구조 설계

각 장르는 문자열의 형태로 입력되므로, 각 장르에 대한 노래를 저장하는 map을 선언한다.

```cpp
map<string, genre> m;
```

여기서 장르는 다음과 같이 구성된다.

```cpp
struct genre{
  int count; // 수록된 모든 곡의 플래이수의 합
  vector<song> songs; // 수록된 곡들의 vector
};
```

문제에서 최종적으로 각 노래들의 index로 이루어진 배열을 return 하므로 각 노래는 index 정보도 함께 포함해야한다.

```cpp
struct song{
  int index;  // 입력받은 index
  int play;   // 노래의 재생 수
};
```

### map을 이용

각 장르(문자열)에 대한 map을 선언해준 뒤, 각 정보를 순회하며 count를 증가 & vector에 노래정보를 저장한다.

이후 map으로 저장된 정보를 count 내림차순 순으로 정렬한다. (vector등을 이용)

내림차순으로 정렬된 정보를 바탕으로 내부 songs를 play순으로 정렬 뒤, 상위 2개의 노래정보를 answer에 저장한다.

이때 노래가 하나만 있을 수 도 있으므로 예외처리함.

## 고생한 점
