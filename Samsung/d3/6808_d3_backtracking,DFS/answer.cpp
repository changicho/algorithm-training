#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define CARD_SIZE 9

using namespace std;

long win, lose;
int cards[CARD_SIZE];
int enemy_cards[CARD_SIZE];

int factorial(int number) {
    int answer = 1;
    while (number > 1) {
        answer *= number;
        number--;
    }
    return answer;
}

void dfs(bool visited[CARD_SIZE], int depth, int my_score, int enemy_score) {
    if (my_score > 85) {
        win += factorial(CARD_SIZE - depth);
        return;
    }
    if (enemy_score > 85) {
        return;
    }

    // 방문 배열을 만들고, 현재 위치마다 체크
    for (int index = 0; index < CARD_SIZE; index++) {
        if (visited[index] == true) {
            continue;
        }
        visited[index] = true;

        int new_my_score = my_score, new_enemy_score = enemy_score;
        if (cards[depth] > enemy_cards[index]) {
            new_my_score += cards[depth] + enemy_cards[index];
        } else {
            new_enemy_score += cards[depth] + enemy_cards[index];
        }

        dfs(visited, depth + 1, new_my_score, new_enemy_score);

        visited[index] = false;
    }
}

void solution(int test_case) {
    win = 0;
    bool check[CARD_SIZE * 2 + 1] = {false};
    // 규영이가 받은 카드
    // 오름차순으로 정렬
    for (int i = 0; i < CARD_SIZE; i++) {
        cin >> cards[i];
        check[cards[i]] = true;
    }

    // 인영이가 가질 수 있는 카드들
    // 오름차순으로 자동 정렬됨
    int index = 0;
    for (int i = 1; i <= 18; i++) {
        if (check[i]) {
            continue;
        }
        enemy_cards[index] = i;
        index++;
    }

    bool visited[CARD_SIZE] = {false};
    dfs(visited, 0, 0, 0);

    cout << "#" << test_case << " " << win << " " << 362880 - win;
    cout << "\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        solution(test_case);
    }

    return 0;
}