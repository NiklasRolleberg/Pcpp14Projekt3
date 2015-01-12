m = 30; n = 150;

fileID = fopen('X.bin');
X = fread(fileID, [m,n], 'double');
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [m,n], 'double');
fclose(fileID);

plot(X,Y,'k*','markerSize', 3)
hold on;

for i=1:n
    plot(X(:,i),(Y(:,i)),'g');
end

for i=1:m
    plot(X(i,:),(Y(i,:)),'r');
end