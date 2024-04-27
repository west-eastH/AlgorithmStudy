package Stack;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj1351 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] arr = br.readLine().toCharArray();
		Stack<Character> stack = new Stack<>();
		int sum = 0;
		int num = 1;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == '(') {
				stack.push(arr[i]);
				num *= 2;
			}
			else if (arr[i] == '[') {
				stack.push(arr[i]);
				num *= 3;
			}
			else if (arr[i] == ')') {
				if (stack.isEmpty() || stack.peek() != '(') {
					System.out.println('0');
					return ;
				}
				if (arr[i - 1] == '(') {
					sum += num;
				}
				stack.pop();
				num /= 2;
			}
			else {
				if (stack.isEmpty() || stack.peek() != '[') {
					System.out.println('0');
					return ;
				}
				if (arr[i - 1] == '[') {
					sum += num;
				}
				stack.pop();
				num /= 3;
			}
		}
		if (!stack.isEmpty()) {
			System.out.println('0');
		} else
			System.out.println(sum);

	}
}
