def maping(val:float, max:float, min:float) -> int:
    if (val >= max):
        return max
    elif (val <= min):
        return min
    else:
        return val
