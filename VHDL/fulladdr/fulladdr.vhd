--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   08-02-2016
-- Module Name:   fulladdr.vhd
--------------------------------------------------------------------------------
use IEEE;
library std_logic_1164.all;

entity fulladdr is
	port(a, b, c_in : in std_logic;
		sum, c_out : out std_logic);
end entity;

architecture arch_fulladdr of fulladdr is
begin
	sum <= a xor b xor c_in;
	c_out <= (a and b) or (a and c_in) or (b and c_in);
end architecture arch_fulladdr;
