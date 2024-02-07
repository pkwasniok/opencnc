import math
import pygame


# Text field
class TextElement():
    def __init__(self, screen, x, y, size):
        self.screen = screen
        self.x = x
        self.y = y
        self.font = pygame.font.SysFont("Source Code Pro", size)

    def draw(self, text):
        self.screen.blit(
                self.font.render(text, True, "white"),
                (self.x, self.y))


# XY axes plotter
class XYPlotterElement():
    def __init__(self, screen, x, y, width, height):
        self.screen = screen
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def draw(self, x, y):
        # Frame
        pygame.draw.rect(
                self.screen,
                "white",
                (self.x, self.y, self.width, self.height),
                4)

        # Grid
        for i in range(self.width // 10-1):
            pygame.draw.line(
                    self.screen,
                    (40, 40, 40),
                    (self.x+i*10+10, self.y+4),
                    (self.x+i*10+10, self.y+self.height-6),
                    1)

        for i in range(self.height // 10-1):
            pygame.draw.line(
                    self.screen,
                    (40, 40, 40),
                    (self.x+4, self.y+i*10+10),
                    (self.x+self.width-6, self.y+i*10+10),
                    1)

        # Limits
        if x > self.width-10:
            x = self.width-10
        elif x < 0:
            x = 0
        elif y > self.height-10:
            y = self.height-10
        if y < 0:
            y = 0

        # X Axis
        pygame.draw.line(
                self.screen,
                (200, 200, 200),
                (self.x+x+4, self.y+4),
                (self.x+x+4, self.y+self.height-5),
                2)

        # Y Axis
        pygame.draw.line(
                self.screen,
                (200, 200, 200),
                (self.x+4, self.y+self.height-y-4),
                (self.x+self.width-5, self.y+self.height-y-4),
                2)


# Z axis plotter
class ZPlotterElement():
    def __init__(self, screen, x, y, width, height):
        self.screen = screen
        self.x = x
        self.y = y
        self.width = width
        self.height = height

    def draw(self, z):
        # Frame
        pygame.draw.rect(
                self.screen,
                "white",
                (self.x, self.y, self.width, self.height),
                4)

        # Grid
        for i in range(self.height // 10 - 1):
            pygame.draw.line(
                    self.screen,
                    (40, 40, 40),
                    (self.x+4, self.y+i*10+10),
                    (self.x+self.width-6, self.y+i*10+10),
                    1)

        if z < 0:
            z = 0
        elif z > self.height:
            z = self.height

        # Axis
        pygame.draw.line(
                self.screen,
                (200, 200, 200),
                (self.x+4, self.y+z),
                (self.x+self.width-5, self.y+z),
                2)


# Stepper motor
class MotorElement():
    def __init__(self, screen, x, y, width, height, label):
        self.screen = screen

        self.x = x
        self.y = y
        self.width = width
        self.height = height

        self.font = pygame.font.SysFont("Source Code Pro", 16)
        self.label = label

    def draw(self, position):
        # Frame
        pygame.draw.rect(
                self.screen,
                (255, 255, 255),
                (self.x, self.y, self.width, self.height),
                4)

        # Label
        self.screen.blit(
                self.font.render(f'{self.label}: {position}', True, "white"),
                (self.x+10, self.y+6))

        # Axis
        radius = self.width * 2/6 - 10
        angle = math.radians((360/200) * (position % 200))
        x1 = radius * math.sin(angle)
        y1 = radius * math.cos(angle)
        pygame.draw.line(
                self.screen,
                (200, 200, 200),
                (self.x+self.width/2, self.y+self.height/2),
                (self.x+self.width/2+x1, self.y+self.height/2+y1),
                5)
