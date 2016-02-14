--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch_t.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity sr_latch_t is
end entity;

architecture arch_sr_latch_t of sr_latch_t is
	signal s, r, q, q_not : std_logic;
begin
	sr_latch_1 : entity work.sr_latch(arch_sr_latch) port map(s, r, q, q_not);
	s <= '1', '0' after 5 ns, '0' after 10 ns, '1' after 15 ns;
	r <= '0', '1' after 5 ns, '0' after 10 ns, '1' after 15 ns;
end architecture arch_sr_latch_t;
