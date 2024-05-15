import pygame
from pygame_globals import *

# do some inital things


#do main

def main():
    
    while (True):
        #event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit
                    exit()

        

        #draw
        

        #update
        pygame.display.update()



#so what

if __name__ == "__main__":
    main()