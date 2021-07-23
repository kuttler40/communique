/*
 *
 * */

#include "_inotify.h"

static PyObject *x_inotify(PyObject *self, PyObject *args){
	
	PyObject *arguments;
	Py_buffer view;
	int length;

	/* Get the passed Python objects */
	if(!PyArg_ParseTuple(args, "O", &arguments)){
		return NULL;
	}
	
	/* Attempt to extract buffer information from it */
	if(PyObject_GetBuffer(arguments, &view, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1){
		return NULL;
	}

	/* check the dimesional array */
	if(view.ndim != 1){
		PyErr_SetString(PyExc_TypeError, "expeceted one dimensional array");
		PyBuffer_Release(&view);
		return NULL;
	}

	/* check the type of the item in the array */
	if(strcmp(view.format, "s") != 0){
		PyErr_SetString(PyExc_TypeError, "expected an array of strings");
		PyBuffer_Release(&view);
		return NULL;
	}
	
	/* Pass the raw buffer and the size to the C function */
	int result;
	result = main(view.buf, view.shape[0]);
	/*
	length = view.shape[0];
	for (int i = 0; i < length; i++){
		printf("%p",view.buf);

	}
	*/
	/* release the buffer */
	PyBuffer_Release(&view);
	return Py_BuildValue("d", -1);

}

static PyMethodDef _inotifyMethods[] = {
	{"_inotify", x_inotify, METH_VARARGS, "Python interface for fputs C library functio		n"},
     {NULL, NULL, 0, NULL}
};
 
static struct PyModuleDef _inotifym= {
     PyModuleDef_HEAD_INIT,
     "x_inotify",
     "Python interface for the fputs C library function",
     -1,
     _inotifyMethods
};

 PyMODINIT_FUNC  PyInit_inotify(void){
         return PyModule_Create(&_inotifym);
}

