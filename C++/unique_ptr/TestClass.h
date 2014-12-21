/*
 * In The Name Of God
 * ========================================
 * [] File Name : TestClass.h
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 22 Dec 2014 01:51:00 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
class TestClass {
	public:
		TestClass() = default;
		TestClass(int number);
		const int& getNumber() const;
		void setNumber(int number);
		~TestClass();

	private:
		int mNumber;
};
