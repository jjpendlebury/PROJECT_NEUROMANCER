#ifndef __NEUROMANCER_DEPLOY_H__
#define __NEUROMANCER_DEPLOY_H__

#include "Matrix_Deploy.h"

enum class layer_type {
	LINEAR,
	SIGMOID,
	RELU
};

class neuromancer {
    private:
    matrix network[7];
	layer_type* layout;
	int layer_count = 3;
	
	void init_network_351();
	void forward_pass();

	public:
	matrix inputs,targets;
	int episodes= 1000;
	neuromancer();	//default params
	void display_network();
	void execute();
};


#endif