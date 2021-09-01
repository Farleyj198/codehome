package edu.farleyj3.Assign03;
import java.util.Scanner;


public class Assign03_2 
{
	public static void main ( String [] args ) 
{
	Scanner input = new Scanner(System.in);
	System.out.println ("Enter the number of sides:");
	int n = input.nextInt();
	System.out.println ("Enter side length:");
	double s = input.nextDouble();
	if(n < 3) 
	{
		System.err.println("ERROR: Number of sides must be >= 3!");
		return;
	}
	double Area = computeArea(n,s);
	System.out.println("Area: " +Area);
}
	public static double computeArea(int n, double s) 
	{
		double Area = (n * (s * s)) / (4 * Math.tan( Math.PI / n)); 
		return Area;
	}	
	
}