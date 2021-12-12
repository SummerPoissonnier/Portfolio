[File,Path] = uigetfile('*.*','Select an image');
image=imread(strcat(Path,File));
%imshow(image);

UpsideDown = flip(image,1);
%imshow(UpsideDown);

LeftRight = flip(image,2);
%imshow(LeftRight)

Negative = 255 - image;
%imshow(Negative)


subplot(2,2,1); imshow(image)
subplot(2,2,2); imshow(UpsideDown)
subplot(2,2,3); imshow(LeftRight)
subplot(2,2,4); imshow(Negative)