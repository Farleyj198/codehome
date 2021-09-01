package edu.farleyj3.Assign02;
import java.util.Scanner;

public class Assign02_2 {
	public static void main ( String [] args ) {
	Scanner input = new Scanner(System.in);
	System.out.println ("Enter the number of sides:");
	double n = input.nextDouble();
	System.out.println ("Enter side length:");
	double s = input.nextDouble();
	if(n < 3) {
		System.out.println("ERROR: Number of sides must be >= 3!");
		return;
	}
	
	double Area = (n * (s * s)) / (4 * Math.tan( Math.PI / n)); 

System.out.println("Area = " +Area);

}
}