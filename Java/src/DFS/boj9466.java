package DFS;

import java.io.*;
import java.util.*;

public class boj9466 {
	static int[] arr;
	static boolean[] visited;
	static boolean[] finished;
	static int cnt;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			int n = Integer.parseInt(br.readLine());
			arr = new int[n + 1];
			visited = new boolean[n + 1];
			finished = new boolean[n + 1];
			cnt = 0;

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 1; i <= n; i++) {
				if (!visited[i]) dfs(i);
			}

			System.out.println(n - cnt);
		}
	}
		static void dfs(int now) {
			if (visited[now]) return;
			visited[now] = true;
			int next = arr[now];

			if (!visited[next]) {
				dfs(next);
			} else {
				if (!finished[next]) {
					cnt++;
					for (int i = next; i != now; i = arr[i]) {
						cnt++;
					}
				}
			}
			finished[now] = true;
		}
	}
