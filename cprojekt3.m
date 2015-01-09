fileID = fopen('X.bin');
X = fread(fileID, [4,4], 'double')
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [4,4], 'double')
fclose(fileID);

%plotmatrix(X,Y)