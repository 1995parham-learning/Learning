var matrix;

matrix = ceil(rand(5) * 10);
disp(matrix);
ind = find(matrix == 8);
disp(ind);
disp(sqrt(matrix));

x = linspace(0, 4 * pi, 1000);
y = sin(x);
plot(x, y);
