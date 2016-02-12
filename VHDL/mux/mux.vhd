--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   mux.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2 is
	port (i0, i1, sel : in std_logic;
		o : out std_logic);
end entity mux_2;

architecture arch_mux_2 of mux_2 is
begin
	o <= i1 when sel = '1' else i0;
end architecture arch_mux_2;
