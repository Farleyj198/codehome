package edu.farleyj3.Assign06;
import java.util.Scanner;
import java.net.URL;
public class GameMap {
	private int mapRows = 0;
	private int mapCols = 0;
	private char [][] mapData = null;
	public GameMap(int mapRows, int mapCols)
	{
		this.mapRows = mapRows;
		this.mapCols = mapCols;
		mapData = new char [0][0];
		for(int i = 0; i < mapCols; i++){
		for(int j = 0; j < mapRows; j++){
			mapData[i][j] = '.';
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
		return super.toString() + "";
		for(int i = 0; i < mapCols; i++){
		for(int j = 0; j < mapRows; j++){
				mapData[i][j] = '#';
	}}

		public abstract void load (Scanner input) throws GameFileException{
    	try {
    		for(int i = 0; i < mapCols; i++){
    			for(int j = 0; j < mapRows; j++){
    				int x;
    				int y;
    				input.nextLine(x) = mapData[i];
    				input.nextLine(y) = mapData[j];
    				 x = Integer.parseInt(x);
    				 y = Integer.parseInt(y);
    				 mapRows = y; 
    				 mapCols = x;
    				mapData[i][j] = mapData[x][y];
    				}}
			for(int j = 0; j < mapRows; j++){
			String t = input.readLine();
			mapData[j] = nextLine(t);
			}
			}			
    		
    			    	catch(Exception e) {
    			    		mapRows = 0;
    			    		mapCols = 0;
    			    		mapData = new char [0][0];
    			      		String message = "Error loading GameMap";
    			    			throw e;
    			    		}
    			    	    	
    	}
		}
	
    	public boolean withinBounds(int x, int y) {
   			if (x<=mapCols)
				if(y<=mapRows)
		{ return true;} 
    	return false;}
    		
    	public char getMapLocation(int x, int y) {
   			if (x>mapCols)
				if(y>mapRows)
					{ return (' ');} 
				else
					{return mapData[y][x];}
			return 0;
    	}   			
    	
    	public boolean canMoveTo(int x, int y) {
    			if (x>mapCols)
    				if(y>mapRows)
    			{return false;}
    			else if (mapData[y][x] == '.') 
    			{return true;}
				return false;
		}

}
	