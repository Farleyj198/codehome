package edu.farleyj3.Assign03;
import java.util.Scanner; 
public class Assign03_3 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String Line;
		do
		{
			System.out.println ("Enter a message:");
			Line = input.nextLine();
			String out = "";
			for(int i = 0; i < Line.length(); i++) 
			{
				char c = Line.charAt(i);
				if(Character.isDigit(c))
				{
					out += "_";
				}
				else 
				{
					out += Line.charAt(i);
				}
			}
		System.out.println(out);
		}while(Line.length()!=0);
	}
}