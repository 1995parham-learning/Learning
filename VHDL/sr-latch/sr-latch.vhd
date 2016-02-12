--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch.vhd
--------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity sr_latch is
	port(s, r : in std_logic;
		q, q_not : out std_logic);
end entity sr_latch;

architecture arch_sr_latch of sr_latch is
	signal fq, fq_not : std_logic;
begin
	fq <= r nor fq_not;
	q <= fq;
	fq_not <= s nor fq;
	q_not <= fq_not;
end architecture arch_sr_latch;
