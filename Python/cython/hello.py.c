/*
 * In The Name Of God
 * ========================================
 * [] File Name : hello.py.c
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 14 Apr 2015 10:13:24 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <Python.h>
#include <stdio.h>

static PyObject *hello_py(PyObject *self, PyObject *args)
{
	const char *name;

	if (!PyArg_ParseTuple(args, "s", &name))
		return NULL;
	
	int retval = printf("Hello Mr.%s\n", name);
	
	return Py_BuildValue("i", retval);
}

static PyMethodDef method_list[] = {
	{"hello_c", hello_py, METH_VARARGS,
		"Print hello $name on screen"},
	{}
};

PyMODINIT_FUNC inithello(void)
{
	Py_InitModule("hello", method_list);
}
