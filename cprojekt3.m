m = 15; n = 15;

fileID = fopen('X.bin');
X = fread(fileID, [m,n], 'double');
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [m,n], 'double');
fclose(fileID);

plot(X,Y,'b*')