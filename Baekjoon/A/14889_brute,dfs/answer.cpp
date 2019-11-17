#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct team {
  int total;
  vector<int> list;
};

int N;
int table[20][20];
int answer = 10000;
bool visited[20];

void dfs(int index, team team1, team team2) {
  if (index == N) {
    answer = min(answer, abs(team1.total - team2.total));
    return;
  }

  // backtracking
  if (answer == 0) {
    return;
  }
  team new_team1 = team1;
  team new_team2 = team2;
  // 현재 인원이 team1에 오는 경우
  if (team1.list.size() != N / 2) {
    for (int i : new_team1.list) {
      new_team1.total += table[i][index];
      new_team1.total += table[index][i];
    }
    new_team1.list.push_back(index);
    dfs(index + 1, new_team1, team2);
  }

  // 현재 인원이 team2에 오는 경우
  if (team2.list.size() != N / 2) {
    for (int i : new_team2.list) {
      new_team2.total += table[i][index];
      new_team2.total += table[index][i];
    }
    new_team2.list.push_back(index);
    dfs(index + 1, team1, new_team2);
  }
}

void solution() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> table[i][j];
    }
  }
  // 팀의 초기 상태를 세팅
  team team1{0, {}};
  team team2{0, {}};

  dfs(0, team1, team2);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}