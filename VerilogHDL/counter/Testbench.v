`timescale 1 ns/100 ps
module Testbench;
	reg clk = 0;
	reg reset = 0;
	wire [3:0] count;

	initial begin
		$dumpfile("Counter.vcd");
		$dumpvars(0, Testbench);
		reset = 0;
		#5 reset = 1;
		#115 reset = 0;
		#760 $stop;
	end
	always #26.5 clk = ~clk;
	Counter cnt(clk, reset, count);
endmodule
