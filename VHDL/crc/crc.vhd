--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   23-02-2016
-- Module Name:   crc.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity crc is
	generic (g : std_logic_vector);
	port (d, clk : in std_logic;
		r : buffer std_logic_vector(g'high - 1 downto g'low) := (others => '0'));
end entity;

architecture arch_crc of crc is
begin
	process (clk)
	begin
		if clk = '1' and clk'event then
			if g(g'low) = '1' then
				r(g'low) <= r(g'high - 1) xor d;
			else
				r(g'low) <= d;
			end if;
			for I in g'low + 1 to g'high - 1 loop
				if g(I) = '1' then
					r(I) <= r(g'high - 1) xor r(I - 1);
				else
					r(I) <= r(I - 1);
				end if;
			end loop;
		end if;
	end process;
end architecture arch_crc;
