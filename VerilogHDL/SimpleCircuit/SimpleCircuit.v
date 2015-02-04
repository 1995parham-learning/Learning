module SimpleCircuit(A, B, C, D, E);
	input A, B, C;
	output	D, E;
	wire	w1;

	and	#(30) G1(w1,A,B);
	not	#(10) G2(E,C);
	or	#(20) G3(D,w1,E);
endmodule
