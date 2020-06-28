<?php
	$func1 = create_function('$a, $b', 'echo $a + $b;');
	echo $func1 . "\n";
	echo $func1(1, 2) . "\n";
