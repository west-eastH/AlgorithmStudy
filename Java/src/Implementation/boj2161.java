import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj2161 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		Queue<Integer> queue = new LinkedList<>();

		// 카드를 큐에 추가
		for (int i = 1; i <= N; i++) {
			queue.add(i);
		}

		// 카드를 버리는 과정 반복
		while (queue.size() > 1) {
			// 버리기
			System.out.print(queue.poll() + " ");
			// 맨 위의 카드를 맨 밑으로 옮기기
			queue.add(queue.poll());
		}

		// 마지막으로 남은 카드 출력
		System.out.println(queue.poll());

		sc.close();
	}
}
