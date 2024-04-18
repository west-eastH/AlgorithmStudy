import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj1475 {
	static int[] nums = new int[10];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String st = br.readLine();
		String replace = st.replace('9', '6');
		char[] arr = replace.toCharArray();
		for (int i = 0; i < replace.length(); i++) {
			nums[arr[i] - '0']++;
		}
		if (nums[6] % 2 == 0)
			nums[6] /= 2;
		else
			nums[6] = nums[6] / 2 + 1;
		int result = 0;
		for (int i = 0; i < nums.length; i++) {
			if (result < nums[i])
				result = nums[i];
		}

		System.out.println(result);
	}
}
