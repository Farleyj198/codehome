package edu.farleyj3.Assign07;
import java.util.Scanner;
//import java.net.URL;
public class GameMap implements Loadable  {
	private int mapRows = 0;
	private int mapCols = 0;
	private char [][] mapData = null;
	public GameMap () {}
	public GameMap(int x, int y)
	{
		mapRows = x;
		mapCols = y;
		mapData = new char [mapRows][mapCols];
		for(int j = 0; j < mapRows; j++){
		for(int i = 0; i < mapCols; i++){
			mapData[j][i] = '.';
		}
		}
	}
	public int getRows()
	{
		return mapRows;
	}
	public int getColumns()
	{
		return mapCols;
	}
	public String toString()
	{
		String s = "";
		for(int j = 0; j < mapRows; j++){
		for(int i = 0; i < mapCols; i++){
			s += mapData[j][i];
	}
		s+="\n";}
	return s;	
	}

	public void load (Scanner input) throws GameFileException{
    	try {
    		mapRows = Integer.parseInt(input.nextLine());
    		mapCols = Integer.parseInt(input.nextLine());
    		mapData = new char [mapRows][mapCols];
    		for(int j = 0; j < mapRows; j++){
    			String t = input.nextLine();
    	 		for(int k = 0; k < mapCols; k++)
    	 		{
    	 			mapData[j][k] = t.charAt(k);
    			}
    		}
    	}
    	catch(Exception e) {
    		mapRows = 0;
    		mapCols = 0;
    		mapData = new char [0][0];
      		String message = "Error loading GameMap";
    			throw new GameFileException (message,e);
    		}
    			    	    	
    	}
		
	
    	public boolean withinBounds(int x, int y) {
        	if(x<mapCols){
        		if(y<mapRows) {
        			if(0<=x){
        				if(0<=y){
        					return true;
        			}}}}
    	return false;}
    		
    	public char getMapLocation(int x, int y) {
    		if(!withinBounds(x,y)) { return (' ');} 
				else
					{return mapData[y][x];}
    	}   			
    	
    	public boolean canMoveTo(int x, int y) {
    		if(!withinBounds(x,y)) {return false;}
    			else if (mapData[y][x] == '.') 
    			{return true;}
				return false;
		}
    	public boolean setMapLocation(int x, int y, char c) {
    		if(withinBounds(x,y)){
    					mapData[y][x] = c;
    					return true;
    			}
    	return false;
    	}

}
	