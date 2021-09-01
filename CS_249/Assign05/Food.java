package edu.farleyj3.Assign05;

public class Food extends Item {
	private double heals = 0.0;
	public double getHeals;
	public Food() {}
	public Food(String newName, double newWeight, double newHeals) {
		super(newName, newWeight);
		heals = newHeals;
	}
	public double getHeals()
		{
			return heals;
		}
		public String toString()
		{
			return super.toString() + ", restores " + heals + " health";
		}

}