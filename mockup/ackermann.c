#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void handler()
{
	//Potential method for running inputs/outputs through all steps?
}

bool sign(double v)
{
	return v >= 0;
}

double* wheel_angle( double t_k ) {
 	double s[2] = {};

 	double pL[5] = {-1.22191897683256 * pow(10, -12),-6.93066613014643 * pow(10, -11),-1.22124643965332 * pow(10, -7),7.24441850583487 * pow(10, -6),0};
 	double pR[5] = {1.20293614700595 * pow(10, -12),-3.39308004771036 * pow(10, -10),2.81827614866493 * pow(10, -7),7.24441850583487 * pow(10, -6),0};
 	double pD = 0.00101523919269833;

 	double deltaL = pD * t_k;
 	double deltaR = deltaL;

 	double correction;

 	if(t_k >= 0){
 		correction = pR[0];
 		for(int n = 1; n < 4; n++){
 			correction = pR[n] + correction * t_k;
 		}
 		deltaR = deltaR + correction;
		 	}
 	else {
 		correction = pL[0];
 		for(int n = 1; n < 4; n++){
 			correction = pL[n] + correction * t_k;
 		}
 		deltaL = deltaL + correction;
 	}
 	s[0] = deltaR;
 	s[1] = deltaL;

	double *s_ptr = s;
 	return s_ptr;
 }

double* step_one(double t_k)
{
	double s[2] = {}
	memcpy(s, wheel_angle(t_k), sizeof(double) + 1);
 	double s_lk = s[0];
 	double s_rk = s[1];

 	double s_k = (s_lk + s_rk)/2;

	double arr[3] = {s_lk, s_rk, s_k};

	double *a_ptr = arr;
	return a_ptr;
}

double* step_two(double s_lk, double s_rk, double s_k, double l, double w)
{
	double r_lfk, r_rfk, r_rrk, r_fk, r_lrk, r_ok;

	r_lfk = 1 / sin(s_lk);
	r_rfk = 1 / sin(s_rk);
	r_fk = 1 / sin(s_k);

	r_ok = sign(r_fk) * sqrt(r_fk * r_fk - l * l);

	r_lrk = r_ok - w / 2;
	r_rrk = r_ok + w / 2;

	double arr[5] = {r_lfk, r_rfk, r_rrk, r_lrk, r_ok};
	double *a_ptr = arr;
	return a_ptr;
}

double* step_three(double r_ok, double r_lfk, double r_rfk, double v_k, double w, double R)
{
	double o_lrk, o_rrk, o_lfk, o_rfk;

	o_lrk = (1 / R) * ((r_ok - w / 2) / r_ok) * v_k;
	o_rrk = (1 / R) * ((r_ok + w / 2) / r_ok) * v_k;

	o_lfk = (1/R) * (r_lfk/r_ok) * v_k;
	o_lfk = (1/R) * (r_rfk/r_ok) * v_k;

	double arr[5] = { o_lrk,
					  o_rrk,
					  o_lfk,
					  o_rfk };
	double *a_ptr = arr;
	return a_ptr;
}

double* step_four(double R, double t_s, double o_lrk, double o_rrk, double o_lfk, double o_rfk)
{
	double s_lrk, s_rrk, s_lfk, s_rfk;

	s_lrk = R * t_s * o_lrk;
	s_rrk = R * t_s * o_rrk;
	s_lfk = R * t_s * o_lfk;
	s_rfk = R * t_s * o_rfk;

	double arr[4] = { s_lrk,
					  s_rrk,
					  s_lfk,
					  s_rfk };
	double *a_ptr = arr;
	return a_ptr;
}

double* step_five(double a_k1, double a_k2, double v_k1, double v_k2, double x_k1, double x_k2, double y_k1, double t_s, double p_k1, double p_k2, double R_k1, double R_k2)
{
	double a_k, v_k, p_k, x_k, y_k;

	a_k = a_k1;
	v_k = v_k1 + (t_s / 2) * (a_k1 + a_k2);
	p_k = p_k1 + (t_s / 2) * ((v_k1 / R_k1) + (v_k2 / R_k2));
	x_k = x_k1 + (t_s / 2) * (v_k1 * cos(p_k1) + v_k2 * cos(p_k2));
	y_k = y_k1 + (t_s / 2) * (v_k1 * sin(p_k1) + v_k2 * sin(p_k2));

	double arr[5] = {a_k, v_k, p_k, x_k, y_k};
	double *a_ptr = arr;
	return a_ptr;
}

