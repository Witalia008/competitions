program drobovi_fokusu;
{$APPTYPE CONSOLE}
function gcd(a,b:longword):longword;
begin
  while (a<>0)and(b<>0) do
    if a>b then a:=a mod b else b:=b mod a;
  if a=0 then gcd:=b else gcd:=a;  
end;
var
  p1,p2,q1,q2,a,b,n:longword;
  q:char;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  p1:=0;
  q:=' ';
  while q<>'/' do
    begin
      read(q);
      if q<>'/' then p1:=p1*10+ord(q)-48;
    end;
  q1:=0;
  while not eoln(input) do
    begin
      read(q);
      q1:=q1*10+ord(q)-48;
    end;
  readln;
  read(q,q);
  b:=0;
  while not eoln(input) do
    begin
      read(q);
      b:=b*10+ord(q)-48;
    end;
  readln;
  q:=' ';
  p2:=0;
  while q<>'/' do
    begin
      read(q);
      if q<>'/' then p2:=p2*10+ord(q)-48;
    end;
  q2:=0;
  while not eoln(input) do
    begin
      read(q);
      q2:=q2*10+ord(q)-48;
    end;
  readln;
  n:=(q1*q2)div gcd(q1,q2);
  n:=(n*b)div gcd(n,b);
  p1:=p1*(n div q1);
  p2:=p2*(n div q2);
  a:=p1;
  fl:=false;
  while (a<p2-1)and(not fl) do
    begin
      inc(a);
      if a mod (n div b)=0 then fl:=true;
    end;
  if fl then writeln(a div (n div b),'/',b) else writeln(-1);
  close(input);
  close(output);
end.
 