public class HelloJNI {
	static {
		System.loadLibrary("HelloJNI");
		/*
		 * Load native library at runtime
		 * HelloJNI.dll (Windows) or libHelloJNI.so (Unixes)
		*/
	}

   	/*
    	* Declare a native method sayHello() that receives nothing and returns void
	*/
   	private native void sayHello();

	/*
	 * Test Driver
	*/
   	public static void main(String[] args) {
      		new HelloJNI().sayHello();
   	}
}
