package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


//boj6593 상범빌딩
public class boj6593 {
	static class Point {
		int x;
		int y;
		int z;
		public Point(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			char[][][] board;
			boolean[][][] visited = new boolean[31][31][31];
			int[][][] dis = new int[31][31][31];
			int[] dx = {-1, 1, 0, 0, 0, 0};
			int[] dy = {0, 0, -1, 1, 0, 0};
			int[] dz = {0, 0, 0, 0, -1, 1};
			StringTokenizer st = new StringTokenizer(br.readLine());
			int L = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			boolean flag = false;
			if (L == 0 && R == 0 && C == 0)
				break;
			Queue<Point> queue = new LinkedList<>();
			board = new char[L][R][C];
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < R; j++) {
					char[] temp = br.readLine().toCharArray();
					for (int k = 0; k < C; k++) {
						board[i][j][k] = temp[k];
						if (temp[k] == 'S')
						{
							queue.add(new Point(i, j, k));
							visited[i][j][k] = true;
						}
					}
				}
				String temp = br.readLine();
			}
			while (!queue.isEmpty()) {
				Point cur = queue.poll();
				if (board[cur.x][cur.y][cur.z] == 'E') {
					System.out.println("Escaped in " + dis[cur.x][cur.y][cur.z] + " minute(s).");
					flag = true;
					break;
				}
				for (int i = 0; i < 6; i++) {
					if (cur.x + dx[i]< 0 || cur.y + dy[i] < 0 || cur.z + dz[i] < 0 || cur.x + dx[i]>= L || cur.y + dy[i] >= R || cur.z + dz[i] >= C)
						continue;
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					int nz = cur.z + dz[i];
					if (board[nx][ny][nz] == '#' || visited[nx][ny][nz])
						continue;
					queue.offer(new Point(nx, ny, nz));
					visited[nx][ny][nz] = true;
					dis[nx][ny][nz] = dis[cur.x][cur.y][cur.z] + 1;
				}
			}
			if (!flag)
				System.out.println("Trapped!");
		}

	}
}
