x = 5;

y = fact(5)

x = 3;
y = 2;
z = perm(x,y)

function p = perm(n,r)
    p = fact(n) * fact(n-r);
end