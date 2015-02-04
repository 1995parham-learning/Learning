`timescale 1 ns/100 ps
module DFlipFlop (reset, din, clk, qout);
	input reset, din, clk;
	output qout;
	reg qout;
	always @ (posedge clk) begin
		if (reset)
			qout <= #8 1'b0;
		else
			qout <= #8 din;
	end
endmodule
