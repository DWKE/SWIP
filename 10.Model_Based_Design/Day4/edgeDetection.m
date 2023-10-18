function edgeDetection() %#codegen

r = raspi;
w = webcam(r);
kern = [1 2 1; 0 0 0; -1 -2 -1];

for k = 1:200
    img = snapshot(w);
    h = conv2(img(:,:,2), kern, 'same');
    v = conv2(img(:,:,2), kern, 'same');
    e = sqrt(h.*h + v.*v);

    edgeImg = uint8((e > 100) * 240);

    newImg = cat(3, edgeImg, edgeImg, edgeImg);

    imshow([img newImg]);

end