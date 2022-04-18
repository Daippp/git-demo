package comp1721.cwk1;

import java.util.Scanner;

public class Guess {
	private int guessNumber;
	private String chosenWord;
	public static String input;
	// Use this to get player input in readFromPlayer()
	private static final Scanner INPUT = new Scanner(System.in);

	// TODO: Implement constructor with int parameter
	public Guess(int num) {
		if (num < 1 || num > 6) {
			throw new GameException("The value of this parameter is not in the allowed range��");
		}
		this.guessNumber = num;
	}

	// TODO: Implement constructor with int and String parameters
	public Guess(int num, String word) {
		char[] charArry = word.toUpperCase().toCharArray();
		int counter = 0;
		for (int i = 0; i < charArry.length; i++) {
			if (charArry[i] >= 'A' && charArry[i] <= 'Z') {
				counter++;
			}
		}
		if (counter != 5 || num < 1 || num > 6) {
			throw new GameException("The value of this parameter is not in the allowed range��");
		}
		this.guessNumber = num;
		this.chosenWord = word.toUpperCase();
	}

	// TODO: Implement getGuessNumber(), returning an int
	public int getGuessNumber() {
		return this.guessNumber;
	}

	// TODO: Implement getChosenWord(), returning a String
	public String getChosenWord() {
		return this.chosenWord;
	}

	// TODO: Implement readFromPlayer()
	public static void readFromPlayer() {
		input = INPUT.nextLine();
	}

	// TODO: Implement compareWith(), giving it a String parameter and String return
	// type
	public String compareWith(String target) {
		String[] output = { "", "", "", "", "" };
		String fizzle = target; // This took an unreasonable amount of time to make
		for (int j = 0; j < 5; j++) {
			String g = this.chosenWord.substring(j, j + 1);
			String a = target.substring(j, j + 1);
			if (g.equals(a)) {
				output[j] = "\033[30;102m " + g + " \033[0m";
				fizzle = fizzle.substring(0, j) + "_" + fizzle.substring(j + 1);
			}
		}
		for (int j = 0; j < 5; j++) {
			String g = this.chosenWord.substring(j, j + 1);

			while (fizzle.contains(g)) {
				if (!output[j].equals(""))
				{
					break;
				}
				output[j] = "\033[30;103m " + g + " \033[0m";
				fizzle = fizzle.substring(0, fizzle.indexOf(g)) + "_" + fizzle.substring(fizzle.indexOf(g)+1);
			}
			if (output[j].equals(""))
				output[j] = "\033[30;107m " + g + " \033[0m";
		}
		String s = String.join("", output);
		return s;

	}

	// TODO: Implement matches(), giving it a String parameter and boolean return
	// type
	public boolean matches(String target) {
		if (target.equals(this.chosenWord)) {
			return true;
		}
		return false;
	}
}
