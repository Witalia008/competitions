program bilshe_vsih;
{$APPTYPE CONSOLE}
var
  a,x,ans,n:int64;
  mas:array[0..20]of longword;
  used:array[0..20]of boolean;
  i:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  fillchar(mas,sizeof(mas),0);
  while not eof(input)do
    begin
      fillchar(used,sizeof(used),0);
      readln(a);
      if a=0 then inc(mas[a]);
      while a<>0 do
        begin
          if a mod n>=0 then x:=a mod n else x:=a mod n+n;
          a:=a div n;
          if not used[x] then
            begin
              inc(mas[x]);
              used[x]:=true;
            end;
        end;
    end;
  x:=0;
  ans:=mas[0];
  for i:=1 to n-1 do
    if mas[i]>ans then
      begin
        ans:=mas[i];
        x:=i;
      end;
  if x<10 then writeln(x) else
    begin
      if x=10 then writeln('A');
      if x=11 then writeln('B');
      if x=12 then writeln('C');
      if x=13 then writeln('D');
      if x=14 then writeln('E');
      if x=15 then writeln('F');
    end;
  close(input);
  close(output);
end.
 