package edu.farleyj3.Assign03;
import java.util.Scanner; 
public class Assign03_1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		double d = input.nextDouble();
		double e = input.nextDouble();
		double f = input.nextDouble();
		double x = computeCramerX(a, b, c, d, e, f); 
		double y = computeCramerY(a, b, c, d, e, f);


		System.out.println("x = " + x);
		System.out.println("y = " + y);

	}
	
	public static double computeCramerX(double a, double b, double c, double d, double e, double f)
	{
		double x = 0;
		x = (e * d - b * f) / (a * d - b * c);
		return x;
	}
	
	public static double computeCramerY(double a, double b, double c, double d, double e, double f)
	{
		double y = 0;
		y = (a * f - e * c) / (a * d - b * c);
		return y;
	}

}
