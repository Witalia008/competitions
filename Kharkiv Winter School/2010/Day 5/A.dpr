program platformu;
 {$APPTYPE CONSOLE}
 var
  n,i,j,k,l,ans:longword;
  y,f,mas:array[1..100000]of int64;
////////////////////////////////////////////////////////////////////////////////
function min(a,b:int64):int64;
 begin
  if a<b then min:=a else min:=b;
 end;
////////////////////////////////////////////////////////////////////////////////
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    read(y[i]);
  f[1]:=0;
  f[2]:=abs(y[2]-y[1]);
  for i:=3 to n do
    f[i]:=min(f[i-1]+abs(y[i]-y[i-1]),f[i-2]+3*abs(y[i]-y[i-2]));
  writeln(f[n]);
  mas[1]:=n;
  ans:=1;
  while n>1 do
    begin
      if (f[n-2]+3*abs(y[n]-y[n-2])=f[n])and(n>2) then
        begin
          dec(n,2);
          inc(ans);
          mas[ans]:=n;
        end else
      if n>1 then
        begin
          dec(n);
          inc(ans);
          mas[ans]:=n;
        end;
    end;
  writeln(ans);
  write(1);
  for i:=ans-1 downto 1 do
    write(' ',mas[i]);
  writeln;   
  close(input);
  close(output);
 end.
