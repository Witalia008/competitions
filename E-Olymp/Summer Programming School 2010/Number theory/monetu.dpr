program monetu;
{$APPTYPE CONSOLE}

var
  mas,x:array[1..16]of longword;
  n,m,i,j,ans,s:longword;
  
procedure srch(k,c,l:longword);
var
  i,j:longword;
begin
  for i:=0 to 2 do
    begin
      if l+mas[k]*i=n then
        begin
          if ans=0 then ans:=c+i;
          if ans>c+i then ans:=c+i;
        end;
      x[k]:=i;  
      if (k<m)and(l+i*mas[k]<n) then srch(k+1,c+i,l+i*mas[k]);
    end;
end;

begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n,m);
  s:=0;
  for i:=1 to m do
    begin
      read(mas[i]);
      s:=s+mas[i]*2;
    end;
  if s<n then writeln(-1) else
    begin
      ans:=0;
      srch(1,0,0);
      writeln(ans);
    end;
  close(input);
  close(output);
end.
 