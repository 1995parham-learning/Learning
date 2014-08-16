<?php
	echo "Waiting for socket to connect..." . "\n";
	$sock = fsockopen("192.168.1.2", 80, $errno, $errstr);
	if($sock <= 0){
		echo "connection failed" . "\n";
		fprintf(STDERR, "socket error : %d : %s\n", $errno, $errstr);
	}else{
		echo "connection established..." . "\n";
		fprintf($sock, "FUCK U ...\n\n");
		fflush($sock);
		while(($answer = fgets($sock)) != ""){
			echo $answer;
		}
		fclose($sock);
	}
