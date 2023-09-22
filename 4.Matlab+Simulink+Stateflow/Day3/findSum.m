function y = findSum(x)
    global SUM_X
    if isempty(SUM_X)
        SUM_X = 0;
    end

    SUM_X = SUM_X + x;
    y = SUM_X;
end