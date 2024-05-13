package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj2573 {
	static int[][] board;
	static boolean[][] visited;
	static int[][] copy;
	static int cnt = 0;
	static int n;
	static int m;
	static int result = 0;

	static int[] dx = {0, -1, 0, 1};
	static int[] dy = {-1, 0, 1, 0};

	public static class Pair{
		int x;
		int y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		copy = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		visited = new boolean[n][m];
		int count = 1;
		while (count == 1) {
			count = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					copy[i][j] = 0;
					if (board[i][j] > 0 && !visited[i][j])
					{
						bfs(i, j);
						count++;
					}
				}
			}
			if (count > 1) {
				System.out.println(result);
				break;
			}
			after();
			result++;
		}
		if (count == 0)
			System.out.println(0);
	}

	static void after() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				if (board[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
							continue;
						}
						if (board[i + dx[k]][j + dy[k]] == 0) {
							cnt++;
						}
					}
				}
				if ((board[i][j] - cnt) > 0)
					copy[i][j] = board[i][j] - cnt;
				else
					copy[i][j] = 0;
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = copy[i][j];
			}
		}
	}


	static void bfs(int i, int j) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(i, j));
		while (!q.isEmpty()) {
			Pair cur = q.poll();
			for (int k = 0; k < 4; k++) {
				if (cur.x + dx[k] < 0 || cur.x + dx[k] >= n || cur.y + dy[k] < 0 || cur.y + dy[k] >= m) {
					continue;
				}
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if (board[nx][ny] == 0 || visited[nx][ny]) {
					continue;
				}
				visited[nx][ny] = true;
				q.add(new Pair(nx, ny));
			}
		}
	}
}
