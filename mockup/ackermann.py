#Ackermann calculation mockup in python

import math
import numpy as np


# See step 3 on page 5 of the Kinematic Vehicle Model v3.pdf file
def step3(dLk, dRk, L):
    R_LFk = L/math.sin(dLk)
    R_RFk = L/math.sin(dRk)
    dk = (dLk + dRk)/2
    R_Fk = L/math.sin(dk)
    R_0k = np.sign(R_Fk)*math.sqrt(R_Fk^2-L^2)
    return R_LFk, R_RFk, R_Fk, R_0k


def block4(r, ts, om_fl, om_fr, om_rl, om_rr):
    """Compute wheel rotations"""
    s_fl = r * ts * om_fl
    s_fr = r * ts * om_fr
    s_rl = r * ts * om_rl
    s_rr = r * ts * om_rr

    return s_fl, s_fr, s_rl, s_rr


# See step 5 on page 5 of the Kinematic Vehicle Model v3.pdf file
def step5(x_k1, y_k1, v_k1, v_k2,psi_k1, psi_k2, t_s, R_0k1, R_0k2, a_k1, a_k2):
    x_k = x_k1+(t_s/2)*(v_k1*math.cos(psi_k1)+v_k2*math.cos(psi_k2))
    y_k = y_k1+(t_s/2)*(v_k1*math.sin(psi_k1)+v_k2*math.sin(psi_k2))
    psi_k = psi_k1+(t_s/2)*((v_k1/R_0k1)+(v_k2/R_0k2))
    v_k = v_k1+(t_s/2)*(a_k1+a_k2)
    a_k = a_k1
    return x_k, y_k, psi_k, v_k, a_k

def instantRadii(slk, srk, sk, l, w):
    rlfk = l / math.sin(slk)
    rrfk = l / math.sin(slk)
    rfk = l / math.sin(sk)

    rok = np.sign(rfk) * math.sqrt(rfk**2 - l**2)

    rlfk = rok - w/2
    rrrk = rok + w/2
    
    return rlfk, rrrk, rok