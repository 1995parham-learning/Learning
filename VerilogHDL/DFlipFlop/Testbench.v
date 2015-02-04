`timescale 1 ns/100 ps
module Testbench;
	reg clk = 0;
	reg reset = 0;
	reg d;
	wire q;

	initial begin
		$dumpfile("DFlipFlop.vcd");
		$dumpvars(0, Testbench);
		d = 1'b0;
		#10 d = 1'b1;
		#20 d = 1'b0;
		#30 d = 1'b1;
		#40 reset = 1;
		#50 $stop;
	end
	always #26.5 clk = ~clk;
	DFlipFlop dff(reset, d, clk, q);
endmodule
