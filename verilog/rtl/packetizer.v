module packetizer #(parameter SRC_ADDR=0)(
 input[31:0] data,
 input[3:0] dest,
 input[4:0] n_pkt,
 output[15:0] packet
);



entity packetizer is
	generic (
		SRC_ADDR	: std_logic_vector(15 downto 0) := (others => '0')
	);
	port (
		slvin	: in  ahb_slv_in_type;
		n_pkt	: in  std_logic_vector(15 downto 0);
		flags	: in  std_logic_vector(7 downto 0);
		pkt_out	: out std_logic_vector(95 downto 0));
end;

architecture a of packetizer is
begin
	process (slvin)
		variable pkt	: std_logic_vector(95 downto 0);
	begin
		pkt := SRC_ADDR & slvin.haddr(15 downto 0) &
			n_pkt & "00000" & slvin.hsize & flags &
			slvin.hwdata;

		pkt_out <= pkt;
	end process;
end;