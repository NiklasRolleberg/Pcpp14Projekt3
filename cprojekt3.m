m = 31; n = 31;

fileID = fopen('X.bin');
X = fread(fileID, [m,n], 'double');
fclose(fileID);

fileID = fopen('Y.bin');
Y = fread(fileID, [m,n], 'double');
fclose(fileID);

plot(X,Y,'b*')
hold on;

for i=1:m
    plot(X(:,i),(Y(:,i)),'r');
end

for i=1:n
    plot(X(i,:),(Y(i,:)),'g');
end