package edu.farleyj3.Assign05;
import java.util.*;
public class Player {
public static final Item item = null;
private double health = 100.0;
private ArrayList<Item> inventory=new ArrayList<>();
public Player() {}
public double getHealth()
{
	return health;
}
public void setHealth(double H)
{
	this.health = H;;
}
public void addItem(Item item) 
{
	inventory.add(item);
}
public boolean useItem(int index) {
if(0<=index && index<inventory.size() && inventory.get(index) instanceof Food)
{
health = health + getHealth();
inventory.remove(index);
return true;
}
else
{return false;}
}
public void printInventory() 
{
	System.out.println("INVENTORY:");
	for(int i = 0;i<inventory.size();i++) {
	System.out.println("Item " + i + ": " + inventory.get(i));
	}
}}