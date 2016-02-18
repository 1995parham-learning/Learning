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
d_avg = d_avg / length(a);
printf('d_avg: %g\n', td_avg);
for i = 1:length(a)
	printf('d_abs_%d: %g\n', i, abs(d_avg - d(i)));
	printf('d_rel_%d: %g\n', i, abs(d_avg - d(i)) / d_avg);
endfor
