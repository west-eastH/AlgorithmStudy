package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj1138 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] tallerCount = new int[N];
		int[] order = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			tallerCount[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < N; i++) {
			int count = 0;
			for (int j = 0; j < N; j++) {
				if (count == tallerCount[i] && order[j] == 0) {
					order[j] = i + 1;
					break;
				}
				if (order[j] == 0) count++;
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			sb.append(order[i]).append(" ");
		}
		System.out.println(sb);

		br.close();
	}
}

