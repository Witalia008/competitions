program avara;
{$APPTYPE CONSOLE}
const
  nmax=1000;
type
  long=record
    len:longword;
    num:array[1..nmax]of shortint;
  end;

function longlen(a:long):longword;
var
  i:longword;
begin
  i:=1;
  while (a.num[i]=0)and(i<nmax) do inc(i);
  longlen:=nmax-i+1;
end;

function multi(a,b:long):long;
var
  i,j,p,s:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for j := nmax downto nmax-b.len do
    for i := nmax downto nmax-a.len do
      begin
        s:=a.num[i]*b.num[j]+p+result.num[i+j-nmax];
        result.num[i+j-nmax]:=s mod 10;
        p:=s div 10;
      end;
  result.len:=longlen(result);
end;

procedure minus(a,b:long;var res:long);
var
  i,z:longword;
begin
  z:=0;
  fillchar(res,sizeof(res),0);
  for i := nmax downto 1 do
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

function comp(a,b:long):shortint;
var
  i:longword;
begin
  i:=1;
  while (a.num[i]=b.num[i])and(i<nmax) do inc(i);
  if a.num[i]=b.num[i] then comp:=0;
  if a.num[i]>b.num[i] then comp:=1;
  if a.num[i]<b.num[i] then comp:=-1;
end;

function comp_0(a:long):boolean;
var
  i:longword;
begin
  comp_0:=true;
  for i := 1 to nmax do
    if a.num[i]<>0 then comp_0:=false;
end;

procedure div_mod(a,b:long;var res,ost:long);
var
  i,n,j:longword;
begin
  fillchar(res,sizeof(res),0);
  fillchar(ost,sizeof(ost),0);
  for i := 1 to nmax do
    begin
      for j := 1 to nmax - 1 do
        ost.num[j]:=ost.num[j+1];
      ost.num[nmax]:=a.num[i];
      n:=0;
      while comp(ost,b)>=0 do
        begin
          inc(n);
          minus(ost,b,ost);
        end;
      res.num[i]:=n;
    end;
  res.len:=longlen(res);
  ost.len:=longlen(ost);  
end;

function gcd(a,b:long):long;
var
  r:long;
begin
  while (not comp_0(a))and(not comp_0(b)) do
    if comp(a,b)>=0 then div_mod(a,b,r,a) else div_mod(b,a,r,b);
  if comp_0(a) then gcd:=b else gcd:=a;
end;

procedure sum(var a:long;b:longword);
var
  i,p,s:longword;
begin
  p:=0;
  a.num[nmax]:=a.num[nmax]+b;
  for i := nmax downto 1 do
    begin
      s:=a.num[i]+p;
      a.num[i]:=s mod 10;
      p:=s div 10;
    end;
  a.len:=longlen(a);  
end;

procedure fout(a:long);
var
  i:longword;
begin
  for i := nmax-a.len+1 to nmax do
    write(a.num[i]);
  writeln;
end;

var
  i,j,n,ko:longword;
  ans,o:long;
  a:array[1..15000]of longword;
  b:array[1..15000]of long;
  used:array[1..15000]of boolean;
begin
  assign(input,'avara.dat');
  reset(input);
  assign(output,'avara.res');
  rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  fillchar(b,sizeof(b),0);
  i:=1;
  ko:=0;
  fillchar(used,sizeof(used),0);
  while i<=n do
    begin
      if not used[i] then
        begin
          j:=a[i];
          inc(ko);
          b[ko].num[nmax]:=1;
          b[ko].len:=1;
          while j<>i do
            begin
              sum(b[ko],1);
              used[j]:=true;
              j:=a[j];
            end;
        end;
      inc(i);
    end;
  ans:=b[1];
  for i := 2 to ko do
    div_mod(multi(ans,b[i]),gcd(ans,b[i]),ans,o);
  fout(ans);
  close(input);
  close(output);
end.

