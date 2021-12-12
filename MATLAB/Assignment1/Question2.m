load('s.mat');

%figure
%montage({s(1).ImageName,s(2).ImageName,s(3).ImageName,s(4).ImageName},'Size', [2 2])

subplot(2,2,1); imshow(s(1).ImageName)
subplot(2,2,2); imshow(s(2).ImageName)
subplot(2,2,3); imshow(s(3).ImageName)
subplot(2,2,4); imshow(s(4).ImageName)
