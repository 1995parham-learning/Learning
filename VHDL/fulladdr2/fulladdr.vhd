--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   08-02-2016
-- Module Name:   fulladdr2.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity fulladdr is
	port(a, b, c_in : in std_logic;
		sum, c_out : out std_logic);
end entity fulladdr;

architecture arch_fulladdr of fulladdr is
	component halfaddr is
		port(a, b : in std_logic;
			sum, c_out : out std_logic);
	end component halfaddr;
	signal temp1 : std_logic;
	signal temp2 : std_logic;
	signal temp3 : std_logic;
begin
	h1 : halfaddr port map(a, b, temp1, temp2);
	h2 : halfaddr port map(temp1, c_in, sum, temp3);
	c_out <= temp3 or temp2;
end architecture arch_fulladdr;
