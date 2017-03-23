import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;




public class App {

	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		int SIZE = 10;
		Queue<Task> tasks = new LinkedList<Task>();

		int[][] array1 = new int[SIZE][SIZE];
		int[][] array2 = new int[SIZE][SIZE];
		
		int resultLine;
		int resultColumn;
		int[][] result;
		int i;
		int j;

	
		resultLine = SIZE;

		Random rand = new Random();
		for (i = 0; i < SIZE; i++) {

			for (j = 0; j < SIZE; j++) {

				array1[i][j] = rand.nextInt() & 1;
			}

		}


		resultColumn = SIZE;


		for (i = 0; i < SIZE; i++) {

			for (j = 0; j < SIZE; j++) {

				array2[i][j] = rand.nextInt() & 1;
			}

		}

		result = new int[resultLine][resultColumn];

		for (i = 0; i < resultLine; i++) {
			tasks.add(new Task(i));
		}

		for (i = 0; i < 2; i++) {
			new Worker(tasks, array1, array2, SIZE, resultColumn, result).start();
		}

		Thread.sleep(1000);
		
		for (i = 0; i < resultLine; i++) {
			for (j = 0; j < resultColumn; j++) {
				System.out.print(result[i][j] + " ");
			}
			System.out.println("\n");
		}

	}

}
