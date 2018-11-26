function lines=powerup(line)
  
  x1=line(:,1);
  x2=line(:,2);
  
  degree = 6;
  out = ones(size(x1(:,1)));
  for i = 1:degree
      for j = 0:i
          out(:, end+1) = (x1.^(i-j)).*(x2.^j);
      end
  end
  
  lines=[line line.^2 line.^3 out];
  %lines=line;
  
  

    
endfunction
