function [dataset] = GenerateUniformDataset(columns,min,max,rows)
dataset = (max - min).*rand(rows,columns) + min;
