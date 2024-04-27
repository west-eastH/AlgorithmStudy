package BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


////boj6593 상범빌딩
//public class Main {
//	class
//	static char[][][] board;
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		while (true) {
//			StringTokenizer st = new StringTokenizer(br.readLine());
//			int L = Integer.parseInt(st.nextToken());
//			int R = Integer.parseInt(st.nextToken());
//			int C = Integer.parseInt(st.nextToken());
//			if (L == 0 && R == 0 && C == 0)
//				break;
//			Queue<Integer, Integer, Integer> queue = new LinkedList<>();
//			board = new char[L][R][C];
//			for (int i = 0; i < L; i++) {
//				for (int j = 0; j < R; j++) {
//					for (int k = 0; k < C; k++) {
//						char[] temp = br.readLine().toCharArray();
//						board[i][j][k] = temp[k];
//						if (temp[k] == 'S')
//
//					}
//				}
//			}
//			for (int i = 0; i < L; i++) {
//				for (int j = 0; j < R; j++) {
//					for (char c : board[i][j]) {
//						System.out.print(c);
//					}
//					System.out.println("");
//				}
//				System.out.println("\n");
//			}
//		}
//
//	}
//}
