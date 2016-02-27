a = [37.24, 37.00, 36.40];
h = [2.21, 2.13, 2.22];

R_avg = 0;
a_avg = 0;
h_avg = 0;

for i = 1:length(a)
	R(i) = (a(i) * a(i)) / (2 * h(i)) + h(i) / 2;	
	printf('R(%d): %g\n', i, R(i));
	R_avg = R_avg + R(i);
endfor
for i = 1:length(a)
	a_avg = a_avg + a(i);
	h_avg = h_avg + h(i);
endfor

a_avg = a_avg / length(a);
h_avg = h_avg / length(a);
R_avg = R_avg / length(a);
printf('R_avg: %g\n', R_avg);

a_abs = [];
h_abs = [];
for i = 1:length(a)
	a_abs(i) = abs(a_avg - a(i));
	h_abs(i) = abs(h_avg - h(i));
	printf('a_abs_%d: %g\n', i, a_abs(i));
	printf('h_abs_%d: %g\n', i, h_abs(i));
endfor

R_abs = [];

for i = 1:length(a)
	R_abs(i) = (4 * a(i) * a_abs(i) * h(i) - 2 * a(i) * a(i) * h_abs(i)) / (4 * h(i) * h(i)) - h_abs(i) / 2;
	printf('R_abs_%d: %g\n', i, R_abs(i));
	printf('R_rel_%d: %g\n', i, abs(R_abs(i)) / R_avg);
endfor
