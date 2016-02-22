--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   22-02-2016
-- Module Name:   register_t.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity n_register_t is
end entity;

architecture arch_n_register_t of n_register_t is
	component n_register is
		generic (N : integer := 8);
		port (d : in std_logic_vector(N - 1 downto 0);
			clk, s_sync, r_sync : in std_logic;
			s_async, r_async : in std_logic;
			q : out std_logic_vector(N - 1 downto 0));
	end component n_register;
	for all:n_register use entity work.n_register(beh_arch_n_register);
	signal clk, s_sync, r_sync, s_async, r_async : std_logic;
	signal d, q : std_logic_vector(0 downto 0);
begin
	reg_1 : n_register generic map (1) port map (d, clk, s_sync, r_sync, s_async, r_async, q);
	d <= "0", "1" after 100 ns, "0" after 200 ns;
end architecture arch_n_register_t;
