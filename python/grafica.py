import numpy as np
import matplotlib.pyplot as plt
import math
x=np.arange(-1,10,0.1)
y=2*np.sin(4*x)-x**2+10*x  #f(x)=2sin(4x)-x^2+10x
#y=2*math.sin(4*x)-x**2+10*x
#f(x)=2sin(4x)-x^2+10x
y=np.sin(x)
plt.plot(x,y)
plt.show()

print (y)
