close all
clear all
clc
max_dims = 20;

output_mat = zeros(0,0);
output_row = zeros(0,0);
for k = 1:20
    n=10;
    test = reshape(1:(k*k), k, k) .';
    test2 = reshape(1:(k*k), k, k) .';
    output_row = k;
    for m = 1:3
    tic;
    for i = 1:10000
        test * test2;
    end
    output_row = [output_row toc];
    end
    output_mat= [output_mat;output_row mean(output_row(2:4))];
    
end

writematrix(output_mat, 'matlab_timing_output.csv')