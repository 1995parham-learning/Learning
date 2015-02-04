`timescale 1ns/100ps

/*
 * A Morre machine sequence detector, searches on it's
 * a input for the 110 sequence.
*/
module SeqDetector (a, clk, reset, w);
	input a, clk, reset;
	output w;
	parameter [1:0] s0 = 2'b00, s1 = 2'b01
		, s2 = 2'b10, s3 = 2'b11;
	reg [1:0] current;

	always @ (posedge clk) begin
		if (reset)
			current = s0;
		else
			case (current)
				s0:
				if (a)
					current <= s1;
				else
					current <= s0;
				s1:
				if (a)
					current <= s2;
				else
					current <= s0;
				s2:
				if (a)
					current <= s2;
				else
					current <= s3;
				s3:
				if (a)
					current <= s1;
				else
					current <= s0;
			endcase
	end
	assign w = (current == s3) ? 1 : 0;

endmodule
