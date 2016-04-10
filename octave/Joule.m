v = [10, 10, 10, 10, 10, 10, 10.1, 10, 10];
a = [1.75, 1.81, 1.83, 1.83, 1.84, 1.84, 1.84, 1.83, 1.84];
delta_t = [0, 3, 6, 8, 10, 12.5, 14, 16, 18];
J=[];

for t = 2:9
	J(t) = (v(t) * a(t) * (t - 1) * 3 * 60) / (280 * 1 * delta_t(t));
	printf('%g\n', J(t));
endfor
