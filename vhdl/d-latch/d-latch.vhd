--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   22-02-2016
-- Module Name:   d-latch.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity d_latch is
	port (d, clk : in std_logic;
		q, q_not : out std_logic);
end entity d_latch;

architecture str_arch_d_latch of d_latch is
	component sr_latch is
		port (s, r, clk : in std_logic;
			q, q_not : buffer std_logic);
	end component sr_latch;
	signal d_not : std_logic;
	for all:sr_latch use entity work.sr_latch(arch_sr_latch);
begin
	d_not <= not d;
	sr_latch_1 : sr_latch port map (d, d_not, clk, q, q_not);
end architecture str_arch_d_latch;

architecture beh_arch_d_latch of d_latch is
begin
	process (clk, d)
	begin
		if clk = '1' then
			q <= d;
			q_not <= not d;
		end if;
	end process;
end architecture beh_arch_d_latch;
