package edu.farleyj3.Assign06;
import java.net.URL;
import java.util.Scanner;
public class Assign06_1 {
	public static void main(String[] args) {
		Scanner A = new Scanner(System.in);
		try {
		System.out.println("Enter map:");
		String x = A.nextLine();
		GameMap m = new GameMap(0, 0);
		Scanner input = Loadable.createScanner(x);
		m.load(input);
		System.out.println(m);
		input.close();
	}
	catch(GameFileException e) {
		System.err.println("Game file error");
		System.err.println(e);
	}
	catch(Exception e) {
		System.err.println("Other error");
		System.err.println(e);
	}

}
}
