picture = imread("pout.tif");
imshow(picture);

picture_double = im2double(picture);
MinInt = min(picture(:));
MaxInt = max(picture(:));
Mean = mean(picture(:));
MinDouble = min(picture_double(:));
MaxDouble = max(picture_double(:));
Average = mean(picture_double(:));

%Info = sprintf('Minimum = %d.\nMaximum = %d.\nAverage = %d.', MinInt, MaxInt, Mean)


