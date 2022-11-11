# pip install graphics.py

"""
TODO:
- Function to draw number line with points on the number line
- Start giving an option menu at this point?    
    - Function for drawing ford circle given a fraction in the line segment
    - Function drawing the ford circles that are tangent to the first ford circle
    - Function that draws the ford circles in the shadows of each of the tangent ford circles
"""

from graphics import *
from fractions import Fraction

SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480

num = int(input("Please give the numerator of your desired fraction within the bounds of your provided interval: "))
den = int(input("Please give the denomintor of your desired fraction within the bounds of your provided interval: "))
f = Fraction(num,den)

win = GraphWin("Draw Ford Circles", SCREEN_WIDTH, SCREEN_HEIGHT)
line_seg = Line(Point(0,SCREEN_HEIGHT/2),Point(SCREEN_WIDTH,SCREEN_HEIGHT/2))
line_seg.draw(win)

step = int(SCREEN_WIDTH/8)
for i in range(0,SCREEN_WIDTH+step,step):
    tick = Line(Point(i,SCREEN_HEIGHT/2-10),Point(i,SCREEN_HEIGHT/2+10))
    tick.draw(win)

win.getMouse() # pause for click in window
win.close()