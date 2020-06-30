module switch #(parameter ID=0, parameter PACKET_WIDTH=48)(
 input clk,
 input nreset,
 input busy_in,
 output busy_out,

 input[PACKET_WIDTH-1:0] local_pkt_in,
 output[PACKET_WIDTH-1:0] local_pkt_out,

 input[PACKET_WIDTH-1:0] east_pkt_in,
 output[PACKET_WIDTH-1:0] east_pkt_out,

 input[PACKET_WIDTH-1:0] west_pkt_in,
 output[PACKET_WIDTH-1:0] west_pkt_out,

 input[PACKET_WIDTH-1:0] north_pkt_in,
 output[PACKET_WIDTH-1:0] north_pkt_in,

 input[PACKET_WIDTH-1:0] south_pkt_in,
 output[PACKET_WIDTH-1:0] south_pkt_in);




endmodule