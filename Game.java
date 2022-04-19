package comp1721.cwk1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDate;

public class Game {
	public int gameNumber;
	public String target;
	private String[] list = new String[6];

	// TODO: Implement constructor with String parameter
	public Game(String filename) throws IOException {
		WordList w = new WordList(filename);
		LocalDate start = LocalDate.of(2021, 6, 19);
		LocalDate now = LocalDate.now();
		int i = (int) (now.toEpochDay() - start.toEpochDay());
		this.gameNumber = i;
		String word = w.getWord(i);
		this.target = word;
	}

	// TODO: Implement constructor with int and String parameters
	public Game(int num, String filename) throws IOException {
		this.gameNumber = num;
		WordList w = new WordList(filename);
		String word = w.getWord(num);
		this.target = word;
	}

	// TODO: Implement play() method
	public void play() {
		int j = 0;
		System.out.print("\n");
		System.out.println("WORDLE " + this.gameNumber);
		System.out.print("\n");
		for (int i = 1; i < 7; i++) {
			System.out.print("Enter guess (" + i + "/6): ");
			Guess.readFromPlayer();
			Guess g = new Guess(i, Guess.input);
			String str1 = g.compareWith(this.target);
			System.out.println(str1);
			list[i-1] =str1;
			if (g.matches(this.target)) {
				j = i;
				break;
			}
			j = 7;

		}
		if (j == 1) {
			System.out.println("Superb - Got it in one!");
		}
		if (j >= 2 && j <= 5) {
			System.out.println("Well done!");
		}
		if (j == 6) {
			System.out.println("That was a close call!");
		}
		if (j == 7) {
			System.out.println("Nope - Better luck next time!");
			System.out.println(this.target);
		}
	}

	private String[] insert(String[] list2, String str1) {
		// TODO Auto-generated method stub
		return null;
	}

	// TODO: Implement save() method, with a String parameter
	public void save(String filename) throws IOException {
		File file = new File(filename);
		PrintWriter output1 = new PrintWriter(file);
		int i = 0;
		while(list[i] != null && i<6){
			String str2 = list[i];
			output1.println(str2);
			i++;
		}
		output1.close();
	}
}
