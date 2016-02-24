--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   23-02-2016
-- Module Name:   crc_t.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity crc_t is
end entity;

architecture arch_crc_t of crc_t is
	component crc is
		generic (g : std_logic_vector);
		port (d, clk : in std_logic;
			r : buffer std_logic_vector(g'high - 1 downto g'low));
	end component;
	signal clk, d : std_logic := '0';
	signal r : std_logic_vector(2 downto 0);
	signal data : std_logic_vector(10 downto 0) := "10101100000";
	signal run : std_logic := '1';
	for all:crc use entity work.crc(arch_crc);
begin
	clk <= not clk after 50 ns when run = '1';
	
	crc_1 : crc generic map ("1011") port map (d, clk, r);
	
	process (clk)
		variable I : natural := data'high + 1;
	begin
		if clk = '1' and clk'event then
			if I > data'low then
				I := I - 1;
				d <= data(I);
			else
				run <= '0';
			end if;
		end if;
	end process;

end architecture;
