function [J, grad] = cost_function(theta, X, y,lambda)

m = length(y); 
h = sigmoid(X*theta);  % 100*1
J = sum(-y'*log(h)-(1.-y)'*log(1-h))/m+lambda/(2*m)*sum(theta((2:length(theta))).^2);

grad = (X'*(h-y)/m)+lambda/m*theta;
grad(1) = (h-y)'*X(:,1)/m;
end
