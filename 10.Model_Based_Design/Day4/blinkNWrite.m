function blinkNWrite() %#codegen

r = raspi();

fileID = fopen('sample.txt', 'w');

for i = 1:7

    writeLED(r,'led0',0);
    pause(0.5);
    writeLED(r,'led0',1);
    pause(0.5);

    fprintf(fileID, 'Blinking on-board LED for count = %d\n', int8(i));

end

fclose(fileID);