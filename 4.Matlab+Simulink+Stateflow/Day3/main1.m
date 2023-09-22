function main1
    x = 5
    nestedfun1
    x
    z = nestedfun2

    function nestedfun1
        x = x + 1;
    end

    function y = nestedfun2
        y = x + 1;
    end
end
