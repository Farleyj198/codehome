package edu.farleyj3.Assign05;

public class Item {
	private String name = "";
	private double weight = 0.0;
	public String getName;
	public double getWeight;
	public Item() {}
public Item(String newName, double newWeight)
{
name = newName;
weight = newWeight;	
}
public String getName()
{
	return name;
}
public double getWeight()
{
	return weight;
}
public String toString()
{
	return name + ", " + weight + " lbs.";
}
}