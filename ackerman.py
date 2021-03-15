import math as m

instantRadii(slk, srk, sk, l, w):
    rlfk = l / math.sin(slk)
    rrfk = l / math.sin(rlk)
    rfk = l / math.sin(sk)

    rok = sign(rfk) * math.sqrt(rfk**2 - l**2)

    rlfk = rok - w/2
    rrrk = rok + w/2


sign(value):
    return lambda value: (value>0) - (value<0)