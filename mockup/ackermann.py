#Ackermann calculation mockup in python


def block4(r, ts, om_fl, om_fr, om_rl, om_rr):
    """Compute wheel rotations"""
    s_fl = r * ts * om_fl
    s_fr = r * ts * om_fr
    s_rl = r * ts * om_rl
    s_rr = r * ts * om_rr

    return s_fl, s_fr, s_rl, s_rr

