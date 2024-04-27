package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj11720 {
	private static int n, m;

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		String st = bf.readLine();
		int result = 0;
		for (int i = 0; i < n; i++) {
			result += st.charAt(i) - '0';
		}
		System.out.println(result);
	}
}