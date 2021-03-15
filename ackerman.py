import math as m

def instantRadii(slk, srk, sk, l, w):
    rlfk = l / m.sin(slk)
    rrfk = l / m.sin(rlk)
    rfk = l / m.sin(sk)

    rok = sign(rfk) * m.sqrt(rfk**2 - l**2)

    rlfk = rok - w/2
    rrrk = rok + w/2
    
    return rlfk, rrrk, rok


def sign(value):
    return 1-(value<=0)