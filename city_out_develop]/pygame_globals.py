import pygame
import os

# import variables
WIDTH = int(os.environ['WIDTH'])
HEIGHT = int(os.environ['HEIGHT'])



# last applying window 
pygame.display.set_caption("Hello")
screen = pygame.display.set_mode((WIDTH, HEIGHT))