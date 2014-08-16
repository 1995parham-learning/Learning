<?php
	fprintf(STDOUT, "%s\n", "Please enter string for validation.");
	$string = "";
	$string = fgets(STDIN);
	echo $string;
	$matchs = array();
	$validation = preg_match("/^(?=a)[a-zA-Z\-]+/", $string, $matchs);
	fprintf(STDOUT, "%s\n", "regex : /^(?=a)[a-zA-Z\\-]+/");
	var_dump($validation);
	var_dump($matchs);
	$matchs = array();
	$regex = <<< __REGEX__
	/^([a-c])x\\1/x
__REGEX__;
	echo $regex . "\n";
	$validation = preg_match($regex, $string, $matchs);
	fprintf(STDOUT, "%s\n", "regex : /([a-c])x\\1x\\1/");
	var_dump($validation);
	var_dump($matchs);	
