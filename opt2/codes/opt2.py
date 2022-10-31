import numpy as np
import matplotlib.pyplot as plt
import cvxpy  as cp

import sys, os
sys.path.insert(0,'/sdcard/Download//chinna/python/CoordGeo')

#if using termux
import subprocess
import shlex
#Defining f(x)
V = 125
def f(r,a):
 return a*np.pi/r + np.pi*r**2
a = 250
label_str = "$Surface area$"

#For minima using gradient ascent
cur_x = 0.1
alpha = 0.001 
precision = 0.00000001 
previous_step_size = 1
max_iters = 100000000 
iters = 0

#Defining derivative of f(x)
df = lambda r: -a*np.pi/r**2 + 2*np.pi*r            

#Gradient ascent calculation
while (previous_step_size > precision) & (iters < max_iters) :
    prev_x = cur_x             
    cur_x -= alpha * df(prev_x)   
    previous_step_size = abs(cur_x - prev_x)   
    iters+=1  

min_val = f(cur_x,a)
print("Minimum value of Surface area is ", min_val, "at","r =",cur_x)
h = V/cur_x**2
print("At r =",cur_x,"h =",h)
#Plotting f(x)
r=np.linspace(1,7,100)
y=f(r,a)
plt.plot(r,y,label=label_str)
#Labelling points
plt.plot(cur_x,min_val,'o')
plt.text(cur_x, min_val,f'P({cur_x:.4f},{min_val:.4f})')

plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.grid()
plt.legend()
plt.savefig('/sdcard/iithfwc/trunk/opt2/im.pdf')
