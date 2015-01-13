<?php
	class Singleton{
		public static function getInstance(){
			static $instance = null;
			if($instance == null){
				$instance = new Singleton();
			}
			return $instance;
		}

		private function __construct(){
			fprintf(STDERR, "I BUIDED\n");
		}
	};
	Singleton::getInstance();
	Singleton::getInstance();
	Singleton::getInstance();
	Singleton::getInstance();
?>
