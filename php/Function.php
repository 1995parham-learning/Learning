<?php
	echo "[1] Calling function with it's name in string :O\n";
	$x = "hello";
	function hello($name){
		echo "Hello $name\n";
	}
	$x("Parham");

	echo "[2] Adding new attribute into class instance with string :O\n";
	$obj = new stdClass();
	$obj->$x = "Test Hello";
	echo "{$obj->hello}\n";
	
	echo "[3] Calling class with it's __invoke and call it's static method with it's name in string\n";
	class say{
		public static function hello($name){
			echo "Hello $name\n";
		}
		
		public function __invoke(){
			echo "you are invoking me (instance of class) as function ??? how dare you !!!!\n";
		}
	}	
	say::$x("Tehran");
	$instance = new Say();
	$instance();

	echo "[4] Getting function arguments in runtime with `func_num_args()` and `func_get_args()`\n";
	function multi_argument(){
		echo func_num_args() . "\n";
		var_dump(func_get_args());
	}
	multi_argument("salam", 1, 2, "khodafez");
	multi_argument("hello", 2, 1, "bye");

	echo "This is nothing ... look source for fun !!!\n";
?>
