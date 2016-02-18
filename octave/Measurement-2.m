printf("Welcome to 3 number GP-1-Lab erroring script :D\n");
len = input("How many number do you have? ");
d = [];
for i = 1:len
	d(i) = input(": ");
endfor
d_avg = 0;
for i = 1:length(d)
	d_avg = d_avg + d(i);
endfor
d_avg = d_avg / length(d);
printf('d_avg: %g\n', d_avg);
d_x_m = 0;
for i = 1:length(d)
	printf('d_abs_%d: %g\n', i, abs(d_avg - d(i)));
	printf('d_rel_%d: %g\n', i, abs(d_avg - d(i)) / d_avg);
	d_x_m = d_x_m + abs(d_avg - d(i));
endfor
printf("d_x_m: %g\n", d_x_m / length(d));
