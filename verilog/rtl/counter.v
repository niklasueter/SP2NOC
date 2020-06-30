module counter #(parameter WIDTH=4)(
 output[WIDTH-1:0] out,
 input enable  ,
 input clk     ,
 input reset);

reg [WIDTH-1:0] out;

always @(posedge(clk))
if (reset) begin
  out <= {WIDTH{1'b0}};
end else if (enable) begin
  out <= out + 1;
end
endmodule
