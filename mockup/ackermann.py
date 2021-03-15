#Ackermann calculation mockup in python

import math 

# See step 3 on page 5 of the Kinematic Vehicle Model v3.pdf file
def step3(dLk, dRk, L):
    R_LFk = L/sin(dLk)
    R_RFk = L/sin(dRk)
    dk = (dLk + dRk)/2
    R_Fk = L/sin(dk)
    R_0k = sign(R_Fk)*sqrt(R_Fk^2-L^2)
    return R_LFk, R_RFk, R_Fk, R_0k


# See step 5 on page 5 of the Kinematic Vehicle Model v3.pdf file
def step5(x_k1, y_k1, v_k1, v_k2,psi_k1, psi_k2, t_s, R_0k1, R_0k2, a_k1, a_k2):
    x_k = x_k1+(t_s/2)(v_k1*cos(psi_k1)+v_k2*cos(psi_k2))
    y_k = y_k1+(t_s/2)(v_k1*sin(psi_k1)+v_k2*sin(psi_k2))
    psi_k = psi_k1+(t_s/2)((v_k1/R_0k1)+(v_k2/R_0k2))
    v_k = v_k1+(t_s/2)(a_k1+a_k2)
    a_k = a_k1
    return x_k, y_k, psi_k, v_k, a_k
