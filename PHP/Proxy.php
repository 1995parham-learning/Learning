<?php
	class LoggingProxy{
		private $target;
		public $myField;

		public function __construct($target){
			$this->target = $target;
		}

		protected function log($line){
			fprintf(STDERR, "%s\n", $line);
		}

		public function __set($name, $value){
			$this->target->$name = $value;
			$this->log("Setting value for $name: $value");
		}

		public function __get($name){
			$value = $this->target->$name;
			$this->log("Getting value for $name: $value");
			return $value;
		}

		public function __call($name, $args){
			$this->log("Calling method $name with: ".implode(", ", $args));
			return call_user_func_array(array($this->target, $name), $args);
		}
	};

	class Test{
		public $number;

		public function __construct($number){
			$this->number = $number;
		}
	};

	$obj = new LoggingProxy(new Test(10));
	echo $obj->number . "\n";
	$obj->number = 100;
	echo $obj->number . "\n";
	$obj->myField;
	$obj->log();
?>
