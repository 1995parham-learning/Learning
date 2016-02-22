--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   22-02-2016
-- Module Name:   register.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity n_register is
	generic (N : integer := 8);
	port (d : in std_logic_vector(N - 1 downto 0);
		clk, s_sync, r_sync : in std_logic;
		s_async, r_async : in std_logic;
		q : out std_logic_vector(N - 1 downto 0));
end entity n_register;

architecture beh_arch_n_register of n_register is
begin
	process (clk, s_async, r_async)
	begin
		if s_async = '1' then
			q <= (others => '1');
		elsif r_async = '1' then
			q <= (others => '0');
		end if;
		if clk = '1' and clk'event then
			if s_sync = '1' then
				q <= (others => '1');
			elsif r_sync = '1' then
				q <= (others => '0');
			else
				q <= d;
			end if;
		end if;
	end process;
end architecture beh_arch_n_register;
