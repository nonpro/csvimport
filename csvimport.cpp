#include "mex.h"

void help();
bool readfile(mxArray *path, mxArray **data, mxArray **names, mxArray **time);

/*
[data, names, time] = csvimport(filename)
*/
extern "C" void mexFunction(int nlhs,mxArray *plhs[],const int nrhs,const mxArray *prhs[])
{
	mexPrintf(nlhs);
	enum args
	{
		e_data=0,
		e_names,
		e_time
	};
	
	char	*filename=0;
	mxArray	*data=0,
			*names=0,
			*time=0;
	
	if!(nrhs<1 && nlhs>1 && nlhs < 4 && mxIsChar(prhs[0]))
	{
		help();
		plhs=0;
		return;
	}
	
	if(!readfile(prhs[0], &data, &names, &time))
	{
		return;
	}
	
	if(nlhs>e_names)
		plhs[e_names] = names;
	else
		mxDestroyArray(names);
	if(nlhs>e_time)
		plhs[e_time] = time;
	else
		mxDestroyArray(time);
	if(nlhs>e_comment)
		plhs[e_comment]	= comment;
	else
		mxDestryArray(comment);
}

void help()
{
	mexMsgTxt("[data, names, time] = csvimport(filename)");
}

bool readfile(mxArray *path, mxArray **data, mxArray **names, mxArray **time)
{
	char *filename;
	int rows=0, cells=0;
	
	filename = mxArrayToString(prhs[0]);
	if(NULL==filename)
	{
		
		return false;
	}
	//-----TODO-----
	
	//--------------
	mxFree(filename);
}