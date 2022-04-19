package comp1721.cwk1;

import java.util.ArrayList;
import java.util.Arrays;
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
		String fizzle = target;
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
				if (!output[j].equals("")) {
					break;
				}
				output[j] = "\033[30;103m " + g + " \033[0m";
				fizzle = fizzle.substring(0, fizzle.indexOf(g)) + "_" + fizzle.substring(fizzle.indexOf(g) + 1);
			}
			if (output[j].equals(""))
				output[j] = "\033[30;107m " + g + " \033[0m";
		}
		String s = String.join("", output);
		return s;

	}

	// TODO: Add compareWith(), display more accessible output for people who have
	// impaired colour vision,
	// or people who rely on screen readers.
	@SuppressWarnings("unlikely-arg-type")
	public String EasycompareWith(String target) {
		// Record the serial numbers of two cases, one in which the input word is
		// exactly correct,
		// and the other in which the input word is contained but in the wrong position
		ArrayList<String> output1 = new ArrayList<String>();
		ArrayList<String> output3 = new ArrayList<String>();
		String fizzle1 = target;
		String ret1 = null; // The output of the case where the input word is exactly right
		String ret2 = null; // The output that contains the input word but is in the wrong position
		// Exactly the same word in the case
		for (int j = 0; j < 5; j++) {
			String g = this.chosenWord.substring(j, j + 1);
			String a = target.substring(j, j + 1);
			if (g.equals(a)) {
				String s = String.valueOf(j + 1);
				output1.add(s);
				fizzle1 = fizzle1.substring(0, j) + "_" + fizzle1.substring(j + 1);
			}
		}
		int m = output1.size();
		if (m >= 1) {
			// Filter out the sequence numbers that match the situation and output them in
			// formatted form
			String[] output2 = { "", "", "", "", "" };
			String s2 = null;
			String s3 = null;
			String s4 = null;
			String s5 = null;
			String s6 = null;
			if (output1.contains("1")) {
				s2 = "1st";
				output2[0] = s2;
			}
			if (output1.contains("2")) {
				s3 = "2nd";
				output2[1] = s3;
			}
			if (output1.contains("3")) {
				s4 = "3rd";
				output2[2] = s4;
			}
			if (output1.contains("4")) {
				s5 = "4th";
				output2[3] = s5;
			}
			if (output1.contains("5")) {
				s6 = "5th";
				output2[4] = s6;
			}
			// Removes null elements from the string array
			output2 = Arrays.stream(output2).filter(s -> (s != null && s.length() > 0)).toArray(String[]::new);
			for (int i = 0; i < output2.length; i++) {
				if (i < output2.length - 2)
					ret1 += output2[i] + ", ";
				if (i >= output2.length - 2 && i < output2.length - 1)
					ret1 += output2[i] + " and ";
				else {
					ret1 += output2[i];
				}
			}
			ret1 = ret1 + "  perfect";
		}
		// Contains words but the words are in the wrong place
		for (int j = 0; j < 5; j++) {
			String g = this.chosenWord.substring(j, j + 1);
			while (fizzle1.contains(g)) {
				if (!output1.equals("")) {
					break;
				}
				String sc = String.valueOf(j + 1);
				output3.add(sc);
				fizzle1 = fizzle1.substring(0, fizzle1.indexOf(g)) + "_" + fizzle1.substring(fizzle1.indexOf(g) + 1);
			}
		}
		int k = output3.size();
		if (k >= 1) {
			// Filter out the sequence numbers that match the situation and output them in
			// formatted form
			String[] output4 = { "", "", "", "", "" };
			String s2 = null;
			String s3 = null;
			String s4 = null;
			String s5 = null;
			String s6 = null;
			if (output1.contains("1")) {
				s2 = "1st";
				output4[0] = s2;
			}
			if (output1.contains("2")) {
				s3 = "2nd";
				output4[1] = s3;
			}
			if (output1.contains("3")) {
				s4 = "3rd";
				output4[2] = s4;
			}
			if (output1.contains("4")) {
				s5 = "4th";
				output4[3] = s5;
			}
			if (output1.contains("5")) {
				s6 = "5th";
				output4[4] = s6;
			}
			// Removes null elements from the string array
			output4 = Arrays.stream(output4).filter(s -> (s != null && s.length() > 0)).toArray(String[]::new);
			for (int i = 0; i < output4.length; i++) {
				if (i < output4.length - 2)
					ret2 += output4[i] + ", ";
				if (i >= output4.length - 2 && i < output4.length - 1)
					ret2 += output4[i] + " and ";
				else {
					ret2 += output4[i];
				}
			}
			ret2 = ret2 + "  correct but in wrong place";
		}
		String ret = "";
		if (ret2 == null && ret1 != null) {
			ret = ret1;
		}
		if (ret1 == null && ret2 != null) {
			ret = ret2;
		} else {
			ret = ret2 + ", " + ret1; // You do not need to consider output statements that do not have the same word
		}
		return ret;
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
