--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch_t.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity d_latch_t is
end entity;

architecture arch_d_latch_t of d_latch_t is
	signal d, clk, q, q_not : std_logic := '0';
begin
	d_latch_1 : entity work.d_latch(beh_arch_d_latch) port map(d, clk, q, q_not);
	d <= '1', '0' after 5 ns, '0' after 10 ns, '1' after 15 ns;
end architecture arch_d_latch_t;
