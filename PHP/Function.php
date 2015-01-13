<?php
	$x = "hello";
	function hello($name){
		echo "Hello $name\n";
	}
	$x("Parham");

	$obj = new stdClass();
	$obj->$x = "Test Hello";
	echo "{$obj->hello}\n";
	
	class say{
		public static function hello($name){
			echo "Hello $name\n";
		}
		
		public function __invoke(){
			echo "you are invoking me as function ??? how dare you !!!!";
		}
	}	
	say::$x("Tehran");
	$instance = new Say();
	$instance();

	function multi_argument(){
		echo func_num_args() . "\n";
		var_dump(func_get_args());
	}
	multi_argument("salam", 1, 2, "khodafez");
	multi_argument("hello", 2, 1, "bye");

	echo "This is nothing ... look syntax for fun !!!\n";
