package DynamicProgramming;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj1010 {
	static int[][] arr = new int [31][31];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i < arr[1].length; i++) {
			arr[1][i] = i;
		}
		for (int i = 2; i < arr.length; i++) {
			for (int j = i; j < arr[i].length; j++) {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
			}
		}
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			System.out.println(arr[n][m]);
		}
	}
}
