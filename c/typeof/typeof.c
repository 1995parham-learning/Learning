/*
 * In The Name Of God
 * ========================================
 * [] File Name : typeof.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun 08 Feb 2015 11:26:09 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */


int main(int argc, char *argv[]) {
  int A = 10;
	// since typeof is a compiler extension, there is not really a definition for it,
	// but in the tradition of C it would be an operator,
	// e.g sizeof and _Alignof are also seen as an operators.
  typeof(A) *a;
  a = &A;
}
