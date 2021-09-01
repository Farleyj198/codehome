package edu.farleyj3.Assign07;

public class Orc extends Monster {
	public Orc(){}
	public Orc(int x, int y, int health){
		super (x,y,health);
	}	
		public void drawToMap(GameMap screen) {
		if(screen == null) {return;}
		else
		{screen.setMapLocation(getX(),getY(),'o');}
	}
}