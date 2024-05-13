package BFS;

import java.io.*;
import java.security.spec.KeySpec;
import java.util.*;

public class Main {
	static int N;
	static int[][] map;
	static int[][] dist;
	static boolean[][] visited;
	static int minDist = 99999999;
	static int islandNum = 1;
	static int[] dx = {0, -1, 0, 1};
	static int[] dy = {-1, 0, 1, 0};
	static Queue<int[]> queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j])
					makeIsland(i, j, islandNum++);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) {
					queue.clear();
					queue.offer(new int[]{i, j});
					dist[i][j] = 0;
					boolean escape = false;
					while (!queue.isEmpty() && !escape) {
						int[] cur = queue.poll();
						int cur_x = cur[0];
						int cur_y = cur[1];

						for (int k = 0; k < 4; k++) {
							int nx = cur_x + dx[k];
							int ny = cur_y + dy[k];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N)
								continue;
							if (dist[nx][ny] >= 0 || map[i][j] == map[nx][ny])
								continue;
							if (map[nx][ny] != 0 && map[i][j] != map[nx][ny]) {
								minDist = Math.min(minDist, dist[cur_x][cur_y]);
								queue.clear();
								escape = true;
								break;
							}
							dist[nx][ny] = dist[cur_x][cur_y] + 1;
							queue.offer(new int[]{nx,ny});
						}
					}
					for (int[] row : dist) {
						Arrays.fill(row, -1);
					}
				}

			}
		}
		System.out.println(minDist);
	}

	private static void printMap() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}

	private static void makeIsland(int i, int j, int islandNum) {
		queue.clear();
		visited[i][j] = true;
		map[i][j] = islandNum;
		queue.offer(new int[]{i, j});
		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			int cur_x = cur[0];
			int cur_y = cur[1];

			for (int k = 0; k < 4; k++) {
				if (cur_x + dx[k] < 0 || cur_x + dx[k] >= N || cur_y + dy[k] < 0 || cur_y + dy[k] >= N)
					continue;
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];
				if (map[nx][ny] == 0 || visited[nx][ny])
					continue;
				map[nx][ny] = islandNum;
				visited[nx][ny] = true;
				queue.offer(new int[]{nx, ny});
			}
		}
	}

	private static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visited = new boolean[N][N];
		dist = new int[N][N];
		for (int[] row : dist) {
			Arrays.fill(row, -1);
		}
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}

}
