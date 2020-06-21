module counter(
 output [7:0] out,
 input 	     enable,
 input 	     clk,
 input 	     reset);

   reg [7:0] reg_out;

always @(posedge(clk))
  if (reset) begin
     reg_out <= 8'b0 ;
  end else if (enable) begin
  reg_out <= out + 1;
  end
assign out = reg_out;
endmodule


