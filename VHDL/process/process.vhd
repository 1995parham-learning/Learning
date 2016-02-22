--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   22-02-2016
-- Module Name:   process.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity process_t is
end entity;

architecture arch_process_t of process_t is
	signal a, b : std_logic := '0';
	signal y_normal, y_fun : std_logic := '0';
	signal w_normal, w_fun, w_var : std_logic := '0';
begin
	a <= '0', '1' after 500 ns, '0' after 1000 ns;
	b <= '0';
	-- checkout when w_normal signal updated.
	process (a, b, y_normal)
	begin
		y_normal <= a xor b;
		w_normal <= y_normal;
	end process;
	-- checkout when w_fun signal updated.
	process (a, b)
	begin
		y_fun <= a xor b;
		w_fun <= y_fun;
	end process;
	-- checkout when w_var signal updated.
	process (a, b)
		variable y_var : std_logic;
	begin
		y_var := a xor b;
		w_var <= y_var;
	end process;
end architecture arch_process_t;
