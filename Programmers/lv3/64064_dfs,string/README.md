# 64064. 불량 사용자

[링크](https://programmers.co.kr/learn/courses/30/lessons/64064)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv3   |   1072   |

## 설계

### 시간복잡도

각 경우를 DFS로 탐색해야 한다. 이 때, 중복되는 경우도 셀 수 있음에 주의한다.

user_id의 경우 최대 크기가 8 이고, banned_id는 user_id의 크기 이하이다.

user_id가 8 이고 banned_id가 4 일 때 최악의 탐색 경우이며 이는 8C4 = 1,680‬ 이다.

이는 int 형으로 충분하다.

### 공간복잡도

nickname은 전부 문자열 이므로 문자열로 생성한다.

### ban이 가능한지 여부

- 비교하는 두 문자열의 크기가 다른경우 false
- index 0부터 문자열을 하나하나 비교
  - "\*" 인 경우 continue
  - 같은 index에서 두 문자열이 다른 경우 false
  - 위 과정을 모두 통과하면 true

### DFS

banned_id의 index를 dfs의 index로 설정하고 탐색한다.

이 경우 index 0 부터 시작해 banned_id의 크기만큼 탐색한 경우 종료한다.

이 때, 정답이 중복될 수 있음에 주의한다.

```cpp
// 다음과 같은 경우 1번, 2번의 경우가 중복됨
banned_id = ["*rodo", "*rodo", "******"];
```

따라서 탐색이 완료되었을 때 answer count를 증가시키는 것이 아닌, 현재 정답 경우를 다듬고 정답 배열에 넣어야 한다.

여러 nickname들을 하나의 경우로 통합 시키는 데는 다음과 같은 방법을 이용한다.

1. nickname 들을 정렬함
2. nickname들을 합침, 대신 중간에 닉네임에 포함되지 않는 특수문자로 구분을 지어줌

위 방법을 수행한 경우 닉네임들은 하나의 문자열로 바꿀 수 있다.

"nick1/nick2/nick3"

dfs 탐색이 끝난 이후, 중복된 정답들을 제거하면, 정답의 갯수가 나온다.

```cpp
void dfs(int index, vector<string> answer) {
  if (index == ban_size) {
    string temp = "";
    sort(answer.begin(), answer.end());
    for (string a : answer) {
      temp += a + ",";
    }
    answers.push_back(temp);
    return;
  }

  for (int i = 0; i < user_id.size(); i++) {
    // 방문 여부 체크
    if (visited_nick[i]) {
      continue;
    }
    // 현재 닉네임 ban 가능한지 여부
    if (canBan(user_id[i], banned_id[index])) {
      answer.push_back(user_id[i]);
      visited_nick[i] = true;

      dfs(index + 1, answer);

      answer.pop_back();
      visited_nick[i] = false;
    }
  }
}
```

## 고생한 점
