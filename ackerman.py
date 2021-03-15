import math

def instantRadii(slk, srk, sk, l, w):
    rlfk = l / math.sin(slk)
    rrfk = l / math.sin(rlk)
    rfk = l / math.sin(sk)

    rok = sign(rfk) * math.sqrt(rfk**2 - l**2)

    rlfk = rok - w/2
    rrrk = rok + w/2
    
    return rlfk, rrrk, rok


def sign(value):
    return 1-(value<=0)