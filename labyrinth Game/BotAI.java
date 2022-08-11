package com.cs370.labyrinth;


import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.backends.lwjgl.LwjglApplicationConfiguration;
import java.awt.AWTException;
import java.awt.Dimension;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.event.InputEvent;
import com.cs370.labyrinth.MyGdxGame;
import com.cs370.labyrinth.Board;
import com.cs370.labyrinth.Tile;
import java.awt.event.KeyEvent;
import java.io.*;



public class BotAI {
	  

public static void main(String[] args) throws IOException, 
AWTException, InterruptedException 
{ 
Robot r = new Robot ();
		LwjglApplicationConfiguration config = new LwjglApplicationConfiguration();
		new LwjglApplication(new MyGdxGame(), config);
Dimension screenSize=Toolkit.getDefaultToolkit().getScreenSize();
int screenHeight = screenSize.height;
int screenWidth = screenSize.width;
MyGdxGame M = new MyGdxGame();
r.delay(2000); 
for (int i=0; i < 100; i++) {	           
int B = (int) (Math.random() * 12);
    switch (B) {
        case 1:
            r.mouseMove((1 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 2:
            r.mouseMove((2 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 3:
            r.mouseMove((3 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 4:
            r.mouseMove((1 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 5:
            r.mouseMove((2 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 6:
            r.mouseMove((3 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 7:
            r.mouseMove((1 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 8:
            r.mouseMove((2 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 9:
            r.mouseMove((3 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 10:
            r.mouseMove((1 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        case 11:
            r.mouseMove((2 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
        default:
            r.mouseMove((4 * 132) + 173, 64);
  r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
            break;
    }
int Dirrection = (int) (Math.random() * 5);
r.delay(500); 
    switch (Dirrection) {
        case 1:
            r.keyPress(KeyEvent.VK_UP);
            r.keyRelease((KeyEvent.VK_UP));
            System.out.println("UP");
            break;
        case 2:
            r.keyPress(KeyEvent.VK_LEFT);
            r.keyRelease((KeyEvent.VK_LEFT));
            if(Gdx.input.isKeyJustPressed(Input.Keys.LEFT))
            {    System.out.println("LEFT");}
               break;
        case 3:
            r.keyPress(KeyEvent.VK_RIGHT);
            r.keyRelease((KeyEvent.VK_RIGHT));
            System.out.println("RIGHT");
            break;
        case 4:
            r.keyPress(KeyEvent.VK_DOWN);
            r.keyRelease((KeyEvent.VK_DOWN));
            System.out.println("DOWN");
            break;
        default:    
            break;
            
    }
}       
} 
	}	    

//
		
//        if(Gdx.input.isKeyJustPressed(Input.Keys.RIGHT))
  //          gameBoard.canPlayerMoveRight(gameBoard.getPlayerLocation(), true);
//		
  //      if(Gdx.input.isKeyJustPressed(Input.Keys.UP))
    //        gameBoard.canPlayerMoveUp(gameBoard.getPlayerLocation(), true);
	//	
  //      if(Gdx.input.isKeyJustPressed(Input.Keys.DOWN))
    //        gameBoard.canPlayerMoveDown(gameBoard.getPlayerLocation(), true);



/*
//r.mouseMove((screenWidth-100) , 0);
//r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
//r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
r.delay(2000); 
//r.mouseMove(((screenWidth/3)-40) , 50);
//r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
//r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
r.delay(5000); 
//r.mouseMove(((screenWidth/2)+(screenWidth/4)+20) , 100);
//r.delay(1000); 

r.mouseMove(((screenWidth/4)+75) , 550);
r.delay(100); 
System.out.println("A");
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}       
System.out.println("A");
r.delay(2000); 

r.mouseMove(((screenWidth/4)+75) , 315);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100);  
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}
r.delay(500); 
r.mouseMove(((screenWidth/4)+75) , 435);
r.delay(10); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);

}       

r.mouseMove(((screenWidth/2)+(screenWidth/8)) , 550);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}       

r.delay(500); 

r.mouseMove(((screenWidth/2)+(screenWidth/8)) , 315);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}
r.delay(500); 
r.mouseMove(((screenWidth/2)+(screenWidth/8)) , 435);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}

r.delay(500); 
r.mouseMove((screenWidth/2)-50, 200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}

r.delay(500); 
r.mouseMove((screenWidth/2)+60, 200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}


r.delay(500); 
r.mouseMove((screenWidth/2)-160, 200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}

r.delay(500); 
r.mouseMove((screenWidth/2)-50, screenHeight-200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}

r.delay(500); 
r.mouseMove((screenWidth/2)+60, screenHeight-200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}


r.delay(500); 
r.mouseMove((screenWidth/2)-160, screenHeight-200);
r.delay(100); 
for (int i=0; i < 10; i++) {	           
r.delay(100); 
r.mousePress(InputEvent.BUTTON1_DOWN_MASK);
r.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
}

*/