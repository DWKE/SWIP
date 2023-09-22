function z = buggy(x)
    n = length(x);
    z = (1:n) ./ x;
    a = myfunction(10);

    function y = myfunction(x)
        y = x + 1;
    end
end