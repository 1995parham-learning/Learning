<?php
	class BadTest{
		private $name = "Parham";

		public function __get($name){
			return $this->$name;
		}

		public function __set($name, $value){
			echo "I set nothing ...";
		}

	}
	$instance = new BadTest();
	echo property_exists($instance, "name") . "\n";
	echo $instance->name . "\n";
	$instance->family = "Alvani";
	echo $instance->family . "\n";

	class GoodTest{
		public static $name;
	}
	GoodTest::$name = "A";
	$instance = new GoodTest();
