--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   22-02-2016
-- Module Name:   d-latch.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity d_latch is
	port (d : in std_logic;
		q, q_not : out std_logic);
end entity d_latch;

architecture arch_d_latch of d_latch is
	component sr_latch is
		port (s, r : in std_logic;
			q, q_not : buffer std_logic);
	end component sr_latch;
	signal d_not : std_logic;
	for all:sr_latch use entity work.sr_latch(arch_sr_latch);
begin
	d_not <= not d;
	sr_latch_1 : sr_latch port map (d, d_not, q, q_not);
end architecture arch_d_latch;
