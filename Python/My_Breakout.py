import pygame
from pygame.locals import *
pygame.init()

ScreenW = 500
ScreenH = 500

Screen = pygame.display.set_mode((ScreenW, ScreenH))
pygame.display.set_caption('My Breakout!')

#Colors Spot
Background =(0,0,0)
Red =(255,0,0)
Yellow =(255,255,0)
Green =(0,255,0)
Blue =(0,0,255)
Black =(50,50,50)
White = (200,200,200)
Gray = (255,255,255)
Textc = (50,150,250)

#Game Values
Cols = 6
Rows = 5
Clock = pygame.time.Clock()
FPS = 60
L_Ball = False
game_over = 0
font = pygame.font.SysFont('Breakout',30)

#Game Text
def draw_text(text,font,Textc,x,y):
    img = font.render(text, True, Textc)
    Screen.blit(img, (x,y))

#Classes
class wall():
    def __init__(self):
        self.width = ScreenW // Cols
        self.height = 50
    def create_wall(self):
        self.blocks = []
        Block_ID = []
        for Row in range(Rows):
            Block_row = []
            for Col in range(Cols):
                Block_x = Col * self.width
                Block_y = Row * self.height
                Rect = pygame.Rect(Block_x, Block_y, self.width, self.height)
                if Row < 1:
                    Strength = 5
                elif Row < 2:
                    Strength = 4
                elif Row < 3:
                    Strength = 3
                elif Row < 4:
                    Strength = 2
                elif Row < 5:
                    Strength = 1
                Block_ID = [Rect, Strength]
                Block_row.append(Block_ID)
            self.blocks.append(Block_row)
    def Draw_wall(self):
        for row in self.blocks:
            for block in row:
                if block[1]==5:
                    Block_col = Black
                elif block[1]==4:
                    Block_col = Blue
                elif block[1]==3:
                    Block_col = Green
                elif block[1]==2:
                    Block_col = Yellow            
                elif block[1]==1:
                    Block_col = Red
                pygame.draw.rect(Screen, Block_col, block[0])
                pygame.draw.rect(Screen, Background, (block[0]), 1)

class bumper():
    def __init__ (self):
        self.reset()
    def move(self):
        self.direction = 0
        Key = pygame.key.get_pressed()
        if Key[pygame.K_LEFT] and self.rect.left > 0:
            self.rect.x -= self.speed
            self.direction = -1
        elif Key[pygame.K_RIGHT] and self.rect.right < ScreenW:
            self.rect.x += self.speed
            self.direction = 1
    def draw(self):
        pygame.draw.rect(Screen, White, self.rect)
        pygame.draw.rect(Screen, Gray, self.rect, 3)
    def reset(self):
        self.height = 20
        self.width = int(ScreenW / Cols)
        self.x = int((ScreenW / 2) - (self.width / 2))
        self.y = ScreenH - (self.height * 2)
        self.speed = 10
        self.rect = Rect(self.x, self.y, self.width, self.height)
        self.direction = 0
class Ball():
    def __init__ (self, x, y):
        self.reset(x,y)

    def move(self):
        collision_thresh= 5
        wall_destroyed = 1
        self.game_over = 0
        row_count = 0
        for row in wall.blocks:
            item_count = 0
            for item in row:
                if self.rect.colliderect(item[0]):
                    if abs(self.rect.bottom - item[0].top) < collision_thresh and self.speed_y > 0:
                            self.speed_y *= -1
                    if abs(self.rect.top - item[0].bottom) < collision_thresh and self.speed_y < 0:
                            self.speed_y *= -1
                    if abs(self.rect.right - item[0].left) < collision_thresh and self.speed_x > 0:
                            self.speed_x *= -1
                    if abs(self.rect.left - item[0].right) < collision_thresh and self.speed_x < 0:
                            self.speed_x *= -1
                    if wall.blocks[row_count][item_count][1] > 1:
                        wall.blocks[row_count][item_count][1] -= 1
                    else:
                        wall.blocks[row_count][item_count][0] = (0,0,0,0)
                if wall.blocks[row_count][item_count][0] != (0,0,0,0):
                     wall_destroyed = 0
                item_count += 1
            row_count +=1
        if wall_destroyed == 1:
            self.game_over = 1                
        if self.rect.left < 0 or self.rect.right > ScreenW:
            self.speed_x *= -1
        if self.rect.top == 0:
            self.speed_y *= -1
        if self.rect.bottom == ScreenH:
            self.game_over = -1
        if self.rect.colliderect(player_bumper):
            if abs(self.rect.bottom - player_bumper.rect.top) < collision_thresh and self.speed_y > 0:
                self.speed_y *= -1
                self.speed_x += player_bumper.direction
                if self.speed_x > self.speed_max:
                    self.speed_x = self.speed_max
                elif self.speed_x < 0 and self.speed_x < self.speed_min:
                    self.speed_x = self.speed_min
            else:
                self.speed_x *= -1
        self.rect.x += self.speed_x
        self.rect.y += self.speed_y
        
        return self.game_over
    def draw(self):
        pygame.draw.circle(Screen, White, (self.rect.x + self.ball_rad, self.rect.y + self.ball_rad), self.ball_rad)
        pygame.draw.circle(Screen, White, (self.rect.x + self.ball_rad, self.rect.y + self.ball_rad), self.ball_rad, 3)
    def reset(self,x,y):
        self.ball_rad= 10
        self.x = x - self.ball_rad
        self.y = y
        self.rect =Rect(self.x, self.y, self.ball_rad * 2, self.ball_rad * 2)
        self.speed_x = 4
        self.speed_y = -4
        self.speed_max = 10
        self.speed_min = -10

#Creating Objects
wall = wall()
wall.create_wall()
player_bumper = bumper()
ball = Ball(player_bumper. x + (player_bumper.width / 2), player_bumper.y - player_bumper.height)

#Game Run
Running = True
while Running:
    Clock.tick(FPS)
    Screen.fill(Background)
    wall.Draw_wall()
    player_bumper.draw()
    ball.draw()
    if L_Ball:
        player_bumper.move()
        game_over = ball.move()
        if game_over != 0: 
            L_Ball = False
    if not L_Ball:
        if game_over == 0:
            draw_text("Click me to start!", font, Textc, ScreenW / 3 , ScreenH / 2 + 100)
        elif game_over == 1:
            draw_text("Victory!", font, Textc, ScreenW / 3 + 50, ScreenH / 2 + 50)
            draw_text("Click me to start again!", font, Textc, ScreenW/3, ScreenH / 2 + 100)
        elif game_over == -1:
            draw_text("Defeat!", font, Textc, ScreenW / 3 + 50, ScreenH / 2 + 50)
            draw_text("Click me to try again!", font, Textc, ScreenW/3, ScreenH / 2 + 100)
            
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            Running = False
        if event.type == pygame.MOUSEBUTTONDOWN and L_Ball == False:
            L_Ball = True
            ball.reset(player_bumper. x + (player_bumper.width / 2), player_bumper.y - player_bumper.height)
            player_bumper.reset()
            wall.create_wall()
    pygame.display.update()            
pygame.quit()
