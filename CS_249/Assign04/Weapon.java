package edu.farleyj3.Assign04; 
public class Weapon {
private String Name = "";
private int Damage = 0;
public Weapon() {
}
public Weapon(String newName, int newDamage)
{
Name = newName;
Damage = newDamage;	
}
public String getName()
{
	return Name;
}
public int getDamage()
{
	return Damage;
}
public void setName(String Name)
{
	this.Name = Name;	
}
public void setDamage(int Damage)
{
	this.Damage = Damage;
}
public String toString()
{
	return Name + ":" + Damage;
}
static void printWeapon(Weapon weapon) 
{
	if(weapon != null) 
	{
	System.out.println("" + weapon);
	}
	else
	{
	System.out.println("No Weapon");	
	}
}
}
