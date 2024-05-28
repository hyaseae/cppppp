import numpy as np
import val
city = np.zeros((16,16),np.uint8)
from functools import cache
@cache
def get_shortest_time(start:[int,int],end:[int,int]) -> int:
    x,y = start
    w,h = city.shape
    




