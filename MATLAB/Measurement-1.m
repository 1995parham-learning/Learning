a = [37.24, 37.00, 36.40];
h = [2.21, 2.13, 2.22];
R_avg = 0;
for i = 1:3
	R(i) = (a(i) * a(i)) / (6 * h(i)) + h(i) / 2;	
	printf('R(%d): %g\n', i, R(i));
	R_avg = R_avg + R(i);
endfor
R_avg = R_avg / 3;
printf('R_avg: %g\n', R_avg);
for i = 1:3
	printf('R_abs_%d: %g\n', i, abs(R_avg - R(i)));
	printf('R_rel_%d: %g\n', i, abs(R_avg - R(i)) / R_avg);
endfor
