function [c, absResult] = addme(a,b)
% ADDME     Add tow values together 
% C = ADDME(A) adds A to itself
% 
% C = ADDME(A,B) adds A and B together
%
% See also SUM, PLUS.
    switch nargin       % n arguments in
        case 2
            c = a + b;
        case 1
            c = a + a;
        otherwise
            c = 0;
    end

    if nargout > 1      % n arguments out
        absResult = abs(c);
    end

end