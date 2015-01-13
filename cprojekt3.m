m = 30; n = 50;

fileID = fopen('X.bin');
X = fread(fileID, [m,n], 'double');
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [m,n], 'double');
fclose(fileID);

plot(X,Y,'k*','markerSize', 1)
hold on;

for i=1:n
    plot(X(:,i),(Y(:,i)),'k');
end

for i=1:m
    plot(X(i,:),(Y(i,:)),'k');
end