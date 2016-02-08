--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   08-02-2016
-- Module Name:   halfaddr.vhd
--------------------------------------------------------------------------------
use IEEE;
library IEEE.std_logic_1164.all

entity halfaddr is
	port(a b : in std_logic;
		sum c_out : out std_logic);
end entity halfaddr;

architecture arch_halfaddr of halfaddr is
begin
	sum <= a xor b;
	c_out <= a and b;
end architecture arch_halfaddr;
