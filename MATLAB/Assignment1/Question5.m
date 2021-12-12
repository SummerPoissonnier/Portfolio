tic
I = imread('coins.png');
[ height width] = size(I);
J = uint8(zeros(size(I)));
for i = 1:height
    for j = 1:width
        J(i,j) = 0.5* I(i,j);
    end
end
imshow(I)
figure, imshow(J)
toc
%a. Yes, the script works as expected.

%b. No, the code will not work after removing unit8
%because there are other values in the code that are doubles and MATLAB 
%automatically assigns numbers as doubles.

%c. The main problem of this code is that the creator did not
%code watching out for doubles and integers and the loop is confusing
%because there are two for loops. The time for the loop to go through and 
%perform the operations is longer than it needs to be since there are two
%for loops when there can be one. 

%d.
tic
I = imread('coins.png');
[height width] = size(I);
I_double = im2double(I);
J = (zeros(size(I_double)));
i=1:height;
for j =1:width
        J(i,j) = 0.5* I_double(i,j);
end
imshow(I)
figure, imshow(J)
toc

%e. My code now runs faster than the previous code and all of my values/
%numbers are of type:double.
