clear;
clc;
lambda=10;

data = load('a.csv');
[a,b]=size(data);
x=data(:,[3:b]);
y=data(:,2);
x=powerup(x);
[m,n]=size(x);
x = [ones(m, 1) x];
init_theta=zeros(n+1,1);


options=optimset('GradObj', 'on', 'MaxIter', 100000000000);
[theta,cost]=fminunc(@(t)(cost_function(t, x, y,lambda)), init_theta, options);
[ans,prob,diff]=get_ans(theta,x,y,m);
diff

data2=load('b.csv');
[c,d]=size(data2);
x_ans=data2(:,[3:d]);
x_ans=powerup(x_ans);
[mm,nn]=size(x_ans);
x_ans = [ones(mm, 1) x_ans];
[ans2,prob2]=get_ans(theta,x_ans,y,mm);
ans2=ans2(:,2);
save ans.csv ans2