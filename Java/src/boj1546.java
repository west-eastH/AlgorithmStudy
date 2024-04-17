import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj1546 {
	public static void main(String[] args) throws IOException {
		int n;
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		float[] arr = new float[n];
		float max = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = Float.parseFloat(st.nextToken());
			if (max < arr[i])
				max = arr[i];
		}
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i] / max;
		}
		System.out.println(100 * sum / n);
	}

}
