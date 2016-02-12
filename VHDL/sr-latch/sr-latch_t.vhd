--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch_t.vhd
--------------------------------------------------------------------------------

entity sr_latch_t is
end entity;

architecture of sr_latch_t of sr_latch_t is
	s, r, q, q_ : signal std_logic;
begin
	sr_latch_1 : entity work.sr_latch port map(s, r, q, q_);
end architecture sr_latch_t;
