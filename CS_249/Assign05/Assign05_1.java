package edu.farleyj3.Assign05;
import java.util.Scanner;

public class Assign05_1 {
Player p = new Player();
Food f = new Food();
Item i = new Item();
Scanner main = new Scanner(System.in);{
do {
	System.out.println("Enter item name and weight: ");
         i.getName = main.toString(); 
		 if(i.getName() =="None"){
		 break;
		 }
		 i.getWeight = main.nextDouble();
		 System.out.println("Is this a food item? [Y/N] ");
		String A = main.nextLine(); 
		if(A == "Y"){
			System.out.println("Enter healing power: ");
			f.getHeals = main.nextDouble();
			p.addItem(Player.item);
		}
			else{
				p.addItem(Player.item);
			}
      }while(i.getName != "None");
	
	p.printInventory();
System.out.println("Which item do you wish to use?");
int itemnum = main.nextInt();
if(p.useItem(itemnum))
{
	System.out.println("Current health: " + p.getHealth());
}
else
{System.out.println("Cannot use this item.");}
}}