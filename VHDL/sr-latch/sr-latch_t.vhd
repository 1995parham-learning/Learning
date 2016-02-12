--------------------------------------------------------------------------------
-- Author:        Parham Alvani (parham.alvani@gmail.com)
--
-- Create Date:   12-02-2016
-- Module Name:   sr-latch_t.vhd
--------------------------------------------------------------------------------

entity sr_latch_t is
end entity;

architecture arch_sr_latch_t of sr_latch_t is
	s, r, q, q_ : signal std_logic;
begin
	sr_latch_1 : entity work.sr_latch port map(s, r, q, q_);
	s <= '1', '0' after 5ns, '0' after 10ns, '1' after 15ns;
	r <= '0', '1' after 5ns, '0' after 10ns, '1' after 15ns;
end architecture arch_sr_latch_t;
