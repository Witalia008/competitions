program skilku_prefiksnuh;
{$APPTYPE CONSOLE}
function cat(n:int64):int64;
var
  c:array[0..51]of int64;
  m,k:longword;
begin
  c[0]:=1;
  for m:=1 to n do
    begin
      c[m]:=0;
      for k:=0 to m-1 do
        c[m]:=c[m]+c[k]*c[m-k-1];
    end;
  cat:=c[n];  
end;
var
  n1,n,a,c:int64;
  I:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n1);
  if n1 mod 2=0 then writeln(0) else
    begin
      n:=n1 div 2;
      if n=0 then c:=1 else c:=cat(n);
      a:=c;
      for i:=1 to n do
        a:=(a*4)mod 1000009;
      for i:=1 to n+1 do
        a:=(a*i)mod 1000009;
      writeln(a);
    end;
  close(input);
  close(output);
end.
