m = 5; n = 5;

fileID = fopen('X.bin');
X = fread(fileID, [m,n], 'double');
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [m,n], 'double');
fclose(fileID);

plot(X,Y,'b*')