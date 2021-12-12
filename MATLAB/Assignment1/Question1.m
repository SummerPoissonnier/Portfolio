image1 = imfinfo("pout.tif");
image2 = imfinfo("coins.png");
image3 = imfinfo("cameraman.tif");
image4 = imfinfo("rice.png");

field1 = 'ImageName'; value1 = {image1.Filename, image2.Filename, image3.Filename, image4.Filename};
field2 = 'Height'; value2 = {image1.Height, image2.Height, image3.Height, image4.Height};
field3 = 'Width'; value3 = {image1.Width, image2.Width, image3.Width, image4.Width};

s = struct(field1, value1, field2, value2, field3, value3);
%s(1)
%s(2)
%s(3)
%s(4)

save ('s.mat','s');



