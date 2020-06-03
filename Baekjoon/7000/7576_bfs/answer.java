import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

class Tomato {
  int y;
  int x;
  int day;

  public Tomato(int y, int x, int day) {
    this.y = y;
    this.x = x;
    this.day = day;
  }
}

public class Main {
  public static int[] directionX = { 0, 0, -1, 1 };
  public static int[] directionY = { -1, 1, 0, 0 };
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String[] information = br.readLine().split(" ");
    Queue<Tomato> q = new LinkedList<Tomato>();

    int col =  Integer.parseInt(information[0]);
    int row =  Integer.parseInt(information[1]);
    int days = 0;


    int[][] tomatoes = new int[1001][1001];
    int total = row * col;
    int count = 0;

    for (int i = 0; i < row; i++) {
      String[] tomatoRow = br.readLine().split(" ");
      for (int j = 0; j < col; j++) {
        tomatoes[i][j] = Integer.parseInt(tomatoRow[j]);

        if (tomatoes[i][j] == 1) {
          q.offer(new Tomato(i, j, 0));
          count += 1;
        } else if (tomatoes[i][j] == -1) {
          total -= 1;
        }
      }
    }

    while (!q.isEmpty()) {
      Tomato cur = q.poll();
      days = cur.day;

      for (int j = 0; j < 4; j++) {
        Tomato next = new Tomato(cur.y + directionY[j], cur.x + directionX[j], cur.day + 1);

        if (next.x < 0 || next.x >= col || next.y < 0 || next.y >= row) {
          continue;
        }

        if (tomatoes[next.y][next.x] == 0) {
          tomatoes[next.y][next.x] = 1;
          count += 1;
          q.offer(new Tomato(next.y, next.x, next.day));
        }
      }

      if (q.isEmpty()) {
        break;
      }
    }

    if (total != count) {
      days = -1;
    }

    bw.write(Integer.toString(days));

    bw.flush();
    bw.close();
  }
}