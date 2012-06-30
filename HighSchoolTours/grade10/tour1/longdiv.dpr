program longdiv;
{$APPTYPE CONSOLE}
const
  nmax=1005;
type
  long=record
    num:array[1..nmax+1]of shortint;
    len:word;
  end;

function longlen(a:long):word;
var
  i:word;
begin
  i:=1;
  while (a.num[i]=0)and(i<nmax) do inc(i);
  longlen:=nmax-i+1;
end;

function comp_0(a:long):boolean;
var
  i:word;
begin
  comp_0:=true;
  for i := 1 to nmax do
    if a.num[i]<>0 then comp_0:=false;
end;

function comp(a,b:long):shortint;
var
  i:word;
begin
  i:=1;
  while (a.num[i]=b.num[i])and(i<nmax) do inc(i);
  if a.num[i]=b.num[i] then comp:=0;
  if a.num[i]>b.num[i] then comp:=1;
  if a.num[i]<b.num[i] then comp:=-1;
end;

procedure minus(a,b:long;var res:long);
var
  i,z:word;
begin
  z:=0;
  fillchar(res,sizeof(res),0);
  for i := nmax  downto 1 do
    begin
      res.num[i]:=a.num[i]-b.num[i]-z;
      if res.num[i]<0 then
        begin
          res.num[i]:=res.num[i]+10;
          z:=1;
        end else z:=0;
    end;
  res.len:=longlen(res);  
end;

procedure div_mod(a,b:long;var res,ost:long);
var
  i,j,n:word;
begin
  fillchar(res,sizeof(res),0);
  fillchar(ost,sizeof(ost),0);
  for i := nmax-a.len to nmax do
    begin
      for j := 1 to nmax - 1 do
        ost.num[j]:=ost.num[j+1];
      ost.num[nmax]:=a.num[i];
      n:=0;
      while comp(ost,b)>=0 do
        begin
          minus(ost,b,ost);
          inc(n);
        end;
      res.num[i]:=n;
    end;
  res.len:=longlen(res);
  ost.len:=longlen(ost);  
end;

function divide(a:long;b:word):long;
var
  i,ost:word;
begin
  ost:=0;
  fillchar(result,sizeof(result),0);
  for i := 1 to nmax do
    begin
      ost:=ost*10+a.num[i];
      result.num[i]:=ost div b;
      ost:=ost mod b;
    end;
  result.len:=longlen(result);
end;

function ostk(a:long;b:word):word;
var
  i,o:word;
begin
  o:=0;
  for i := 1 to nmax do
    o:=(o*10+a.num[i])mod b;
  ostk:=o;
end;

function nMult(a:long;nom:word):word;
var
  i:word;
begin
  result:=0;
  while ostk(a,nom)=0 do
    begin
      inc(result);
      a:=divide(a,nom);
    end;
end;

function GCD(a,b:long):long;
var
  r:long;
begin
  while (not comp_0(a))and(not comp_0(b)) do
    if comp(a,b)>=0 then div_mod(a,b,r,a) else
      div_mod(b,a,r,b);
  if comp_0(a) then GCD:=b else GCD:=a;
end;

function entire(var a,b:long):word;
var
  i:word;
begin
  result:=0;
  for i := 1 to nmax - 1 do
    a.num[i]:=a.num[i+1];
  a.num[nmax]:=0;
  while comp(a,b)>=0 do
    begin
      inc(result);
      minus(a,b,a);
    end;
end;

procedure div_dec(a,b:long);
var
  ost,res,_gcd,x:long;
  i,j,k2,k5,k:word;
begin
  _gcd:=gcd(a,b);
  div_mod(a,_gcd,a,ost);
  div_mod(b,_gcd,b,ost);
  div_mod(a,b,res,ost);
  for i := nmax-res.len+1 to nmax do write(res.num[i]);
  if not comp_0(ost) then
    begin
      write('.');
      k2:=nMult(b,2);
      k5:=nMult(b,5);
      if k2>k5 then k:=k2 else k:=k5;
      for i := 1 to k do
        write(entire(ost,b));
      if not comp_0(ost) then
        begin
          write('(');
          x:=ost;
          write(entire(ost,b));
          while comp(ost,x)<>0 do
            write(entire(ost,b));
          write(')');
        end;   
    end;
end;

var
  a,b:long;
  i,j:word;
  q:char;
begin
  assign(input,'longdiv.dat');
  reset(input);
  assign(output,'longdiv.res');
  rewrite(output);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  while not eoln(input) do
    begin
      inc(a.len);
      read(q);
      a.num[a.len]:=ord(q)-ord('0');
    end;
  i:=a.len;
  j:=nmax;
  while i>0 do
    begin
      a.num[j]:=a.num[i];
      a.num[i]:=0;
      dec(i);
      dec(j);
    end; 
  readln;
  while not eoln(input) do
    begin
      inc(b.len);
      read(q);
      b.num[b.len]:=ord(q)-ord('0');
    end;
  i:=b.len;
  j:=nmax;
  while i>0 do
    begin
      b.num[j]:=b.num[i];
      b.num[i]:=0;
      dec(i);
      dec(j);
    end;
  div_dec(a,b);
  writeln;  
  close(input);
  close(output);
end.
