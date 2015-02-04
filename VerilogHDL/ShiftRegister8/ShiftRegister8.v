module ShiftRegister8 (sl, sr, clk, parIn, parOut, mode);
	input sl, sr;
	input clk;
	input [7:0] parIn;
	output reg [7:0] parOut;
	input [1:0] mode;

	always @ (negedge clk) begin
		case (mode)
			0: parOut <= parOut;
			1: parOut <= {sl, parOut [7:1]};
			2: parOut <= {parOut [6:0], sr};
			3: parOut <= parIn;
			default: parOut <= 8'bX;
		endcase
	end
endmodule
