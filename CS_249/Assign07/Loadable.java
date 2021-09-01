package edu.farleyj3.Assign07;
import java.util.Scanner;
import java.io.File;
import java.net.URL;
public interface Loadable {
		public abstract void load (Scanner input) throws GameFileException;
		public static Scanner createScanner(String path) throws Exception {			
			String y = "http";
		if(path.contains(y)) 
		{
			URL url = new URL(path);
			Scanner input = new Scanner(url.openStream());
			return input;
		}
		else
		{
			File myFile = new File(path);
			Scanner input = new Scanner(myFile);
			return input;
		}
}
}

