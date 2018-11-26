function [ans,proba,diff]=get_ans(theta,x,y,m)

proba=sigmoid(x*theta);
ans=zeros(m,2);
diff=0;
for i=1:m,
  ans(i,1)=i;
  if proba(i)>0.5,
    ans(i,2)=1;
  endif
  if ans(i,2)!=y(i),
    diff=diff+1;
  endif
endfor



endfunction
