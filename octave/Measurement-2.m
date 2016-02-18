d = [37.24, 37.00, 36.40];
d_avg = 0;
for i = 1:length(d)
	d_avg = d_avg + d(i);
endfor
R_avg = R_avg / length(a);
printf('d_avg: %g\n', R_avg);
for i = 1:length(a)
	printf('d_abs_%d: %g\n', i, abs(d_avg - d(i)));
	printf('d_rel_%d: %g\n', i, abs(d_avg - d(i)) / d_avg);
endfor
