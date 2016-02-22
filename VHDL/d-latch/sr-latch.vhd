--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity sr_latch is
	port(s, r : in std_logic;
		q, q_not : buffer std_logic);
end entity sr_latch;

architecture arch_sr_latch of sr_latch is
begin
	q <= r nor q_not;
	q_not <= s nor q;
end architecture arch_sr_latch;
