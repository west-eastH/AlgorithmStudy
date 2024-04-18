import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj5014 {
	static int[] board;
	static boolean[] visited;
	static int F, S, G, U, D;
	static void bfs(int s) {
		visited[s] = true;
		Queue<Integer> queue = new LinkedList<>();
		queue.add(s);
		while (!queue.isEmpty()) {
			int n = queue.poll();
			if (n + U <= F) {
				if (!visited[n + U]) {
					board[n + U] = board[n] + 1;
					visited[n + U] = true;
					queue.add(n + U);
				}
			}
			if (n - D > 0) {
				if (!visited[n - D]) {
					board[n - D] = board[n] + 1;
					visited[n - D] = true;
					queue.add(n - D);
				}
			}
		}
		if (S != G && board[G] == 0)
			System.out.println("use the stairs");
		else
			System.out.println(board[G]);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		F = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		U = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		board = new int[F + 1];
		visited = new boolean[F + 1];
		bfs(S);
	}
}
