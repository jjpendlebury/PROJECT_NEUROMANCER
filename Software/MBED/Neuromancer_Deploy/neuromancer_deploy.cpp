#include "neuromancer_deploy.h"

neuromancer::neuromancer(){
    printf("CREATING NEUROMANCER INSTANCE...\n");
    //network = new matrix[2*layer_count];   //default number of layers
    layout = new layer_type[layer_count];//set up layer types
    layout[0] = layer_type::LINEAR;
    layout[1] = layer_type::SIGMOID;
    layout[2] = layer_type::LINEAR;
    init_network_351();
    display_network();

}

void neuromancer::init_network_351(){
    printf("ALLOCATING MATRICES...\n");
    //manual allocation for now
    matrix input_slice(3,1);
    matrix W1(10,3);
    matrix net1(10,1);
    network[0]=input_slice;
    network[1]=W1;
    network[2]=net1;
    //second layer
    matrix a2(10,1);
    matrix a2hat(11,1,1);
    network[3] = a2;
    network[4] = a2hat;
    //third layer
    matrix W2(2,11);
    matrix net2(2,1);
    network[5] = W2;
    network[6] = net2;
}
void neuromancer::forward_pass(){
    for(int i = 0; i < layer_count; i++){
        if(layout[i] == layer_type::LINEAR){
            network[(i*2)+2] = network[(i*2)+1].multiply(network[(i*2)]);
        }
    }
}
void neuromancer::display_network(){
    printf("layer count= %d\n", layer_count );
    //network[0].print();
    for (int i = 0; i < 2*layer_count; i++){
        printf("\nMatrix #%d\n",i);
        network[i].dims.print_dims();
        network[i].print();
        
    }
}
void neuromancer::execute(){

}