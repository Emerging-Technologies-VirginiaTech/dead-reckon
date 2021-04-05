#include <stdio.h>
#include <math.h>

void handler() {
	//Potential method for running inputs/outputs through all steps?
}

double step_one( double t_k ) {
	double s_lk = wheel_angle_left(t_k);
	double s_rk = wheel_angle_right(t_k);
	
	double s_k = (s_lk + s_rk)/2;
	
	double arr[3] = {s_lk, s_rk, s_k};
	return arr;
}

double step_two( double s_lk, double s_rk, double s_k, double l, double w ) {
	double r_lfk, r_rfk, r_rrk, r_lrk, r_ok;
	
	r_lfk = 1 / sin(s_lk);
	r_rfk = 1 / sin(s_rk);
	r_fk = 1 / sin(s_k);
	
	r_ok = sign(r_fk) * sqrt(r_fk * r_fk - l*l);
	
	r_lrk = r_ok - w/2;
	r_rrk = r_ok + w/2;
	
	double arr[5] = {r_lfk, r_rfk, r_rrk, r_lrk, r_ok}
	return arr;
}

double step_three( double r_ok, double r_lfk, double r_rfk, double v_k, double w, double R) {
	double o_lrk, o_rrk, o_lfk, o_rfk;
	
	o_lrk = (1/R) * ((r_ok-w/2)/r_ok) * v_k
	o_rrk = (1/R) * ((r_ok+w/2)/r_ok) * v_k
	
	o_lfk = (1/R) * (r_lfk/r_ok) * v_k)
	o_lfk = (1/R) * (r_rfk/r_ok) * v_k)
	
	double arr[5] = {o_lrk, o_rrk, o_lfk, o_rfk}
	return arr;
}

double step_four( double R, double t_s, double o_lrk, double o_rrk, double o_lfk, double o_rfk ) {
	double s_lrk, s_rrk, s_lfk, s_rfk;
	
	s_lrk = R * t_s * o_lrk;
    s_rrk = R * t_s * o_rrk;
    s_lfk = R * t_s * o_lfk;
    s_rfk = R * t_s * o_rfk;
	
	double arr[4] = {s_lrk, s_rrk, s_lfk, s_rfk}
	return arr;
}

double step_five( double a_k1, double a_k2, double v_k1, double v_k2, double x_k1, double x_k2, double y_k1, double t_s, double p_k1, double p_k2, double R_k1, double R_k2 ) {
	double a_k, v_k, p_k, x_k, y_k;
	
	a_k = a_k1;
	v_k = v_k1 + (t_s/2) * (a_k1 + a_k2);
	p_k = p_k1 + (t_s/2) * ((v_k1/R_k1) + (v_k2/R_k2));
	x_k = x_k1 + (t_s/2) * (v_k1 * cos(p_k1) + v_k2 * cos(p_k2));
	y_k = y_k1 + (t_s/2) * (v_k1 * sin(p_k1) + v_k2 * sin(p_k2));
	
	double arr[5] = {a_k, v_k, p_k, x_k, y_k};
	return arr;
	
}

bool sign(double v) {
	return v >= 0;
}

double wheel_angle_right( double t_k ) {
	//Not implemented
	return 0;
}

double wheel_angle_left( double t_k) {
	//Not implemented
	return 0;
}