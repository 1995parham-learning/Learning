--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   08-02-2016
-- Module Name:   or3.vhd
--------------------------------------------------------------------------------
use IEEE;
library IEEE.std_logic_1164.ALL;


entity or3 is
	port (i1, i2, i3 : in std_logic;
		o1: out std_logic);
end entity or3;

architecture arch_or3 of or3 is
begin
	o1 <= i1 or i2 or i3 after 2 ns;
end architecture arch_or3;
