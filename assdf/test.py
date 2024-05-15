# made by 30413 신동호, 05.06.12pm
import pygame
from pygame_globals import *

# do some inital things
z = [[0 for j in range(0,WIDTH)] for i in range(0,HEIGHT)]

# functions

def dist(a,b,c,d):
    return (a-c)**2+(b-d)**2

def change_z(mouse_x,mouse_y,radius,val=100):
    from pygame_functions import maping
    for y in range(0,HEIGHT):
        for x in range(0,WIDTH):
            z += maping(dist(x,y,mouse_x,mouse_y))





#do main

def main():
    from color import BLACK
    screen.fill()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit
                    exit()
                if event.key == pygame.K_SPACE:
                    if pygame.mouse.get_pressed():
                        pass

        pygame.display.update()

#so what

if __name__ == "__main__":
    main()