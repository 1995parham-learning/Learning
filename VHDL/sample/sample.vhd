--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   08-02-2016
-- Module Name:   sample.vhd
--------------------------------------------------------------------------------

entity sample is
	port (i1, i2, i3 : in std_logic;
		o1 : out std_logic);
end entity;

architecture arch_sample of sample is
	signal tmp1 : std_logic;
	signal tmp2 : std_logic;
	signal tmp3 : std_logic;
begin
	tmp1 <= i1 and i2;
	tmp2 <= i2 and i3;
	tmp3 <= i1 and i3;
	o1 <= tmp1 or tmp2 or tmp3 after 2 ns;
end architecture arch_sample;
