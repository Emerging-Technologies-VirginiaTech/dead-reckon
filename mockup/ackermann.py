#Ackermann calculation mockup in python

# See step 3 on page 5 of the Kinematic Vehicle Model v3.pdf file
def step3(dLk, dRk, L):
    R_LFk = L/sin(dLk)
    R_RFk = L/sin(dRk)
    dk = (dLk + dRk)/2
    R_Fk = L/sin(dk)
    R_0k = sign(R_Fk)*sqrt(R_Fk^2-L^2)
    return R_LFk, R_RFk, R_Fk, R_0k
