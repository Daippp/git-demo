package comp1721.cwk1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class WordList {
	private List<String> words;

	// TODO: Implement constructor with a String parameter
	public WordList(String filename) throws IOException {
		String path = filename;
		FileReader fileReader = new FileReader(path);
		try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
			List<String> list = new ArrayList<String>();
			String str = null;
			while ((str = bufferedReader.readLine()) != null) {
				if (str.trim().length() > 2) {
					list.add(str);
				}
			}
			this.words = list;
		}
		
	}

	// TODO: Implement size() method, returning an int
	public int size() {
		int count = 0;
		for (int i = 0; i < words.size(); i++) {
			count = i+1;
		}
		return count;
	}

	// TODO: Implement getWord() with an int parameter, returning a String
	public String getWord(int n) throws GameException{
		if (n < 0 || n >= words.size()) {
			throw new GameException("the value of this parameter is invalid");
		}
		return words.get(n);
	}
}
