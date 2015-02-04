module Testbench;
	wire	D, E;
	reg	A, B, C;

	SimpleCircuit M1(A, B, C, D, E);

	initial
	begin
		$dumpfile("SimpleCircuit.vcd");
		$dumpvars(0, Testbench);
		A=1'b0;
		B=1'b0;
		C=1'b0;
		#100 A=1'b1;
		#100 B=1'b1;
		#100 C=1'b1;
	end
	initial
	begin
		#200 $finish;
	end
endmodule
