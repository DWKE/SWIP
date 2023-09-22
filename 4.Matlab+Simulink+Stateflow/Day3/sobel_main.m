clear all; close all; clc;

% codegen sobel

im = imread('hello.jpg');
figure(1);
image(im);

gray = (0.2989 * double(im(:,:,1)) +...
        0.5870 * double(im(:,:,2)) +...
        0.1140 * double(im(:,:,3)))/255;
figure(2);
image(gray);

edgeIm_1_1 = sobel(gray, 0.3);
figure(3);
image(edgeIm_1_1);

edgeIm_1_2 = repmat(edgeIm_1_1, [1 1 3]);
figure(4);
image(edgeIm_1_2);

edgeIm_2_1 = sobel_mex(gray, 0.3);
figure(5);
image(edgeIm_2_1);

edgeIm_2_2 = repmat(edgeIm_2_1, [1 1 3]);
figure(6);
image(edgeIm_2_2);