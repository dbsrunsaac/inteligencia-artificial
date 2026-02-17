clc, clear, close all;

% Read matrix
data = readmatrix('rpm_motor.csv');

plot(data);

disp(mean(data))