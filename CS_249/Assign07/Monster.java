package edu.farleyj3.Assign07;
import java.util.Scanner;
public abstract class Monster implements Drawable,Loadable {
private int x = 0;
private int y = 0;
private int health = 100;
protected Monster(){}
protected Monster(int newX, int newY, int newHealth){
	x = newX;
	y = newY;
	health = newHealth;
}
public int getX() {return x;}
public int getY() {return y;}
public int getHealth() {return health;}
public void setX(int x) {this.x=x;}
public void setY(int y) {this.y=y;}
public void setHealth(int health) {this.health=health;}
public void load (Scanner input) throws GameFileException{
try {
	x=input.nextInt();
    y=input.nextInt();
    health=input.nextInt();
} 
catch(Exception e) {	
	x = 0;
	y = 0; 
	health = 100;
	String message = "Error loading Monster";
	throw new GameFileException (message,e);
}
}
}
