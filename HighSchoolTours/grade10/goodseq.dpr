program goodseq;
{$APPTYPE CONSOLE}
const
  nmax=200;
type
  tmas=record
    len:word;
    n:array[1..nmax]of longword;
  end;

function longlen(a:tmas):longword;
var
  i:word;
begin
  i:=1;
  while (a.n[i]=0)and(i<nmax) do inc(i);
  longlen:=nmax-i+1;
end;

function sum(a,b:tmas):tmas;
var
  i,p,s:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for i := nmax downto 1 do
    begin
      s:=a.n[i]+b.n[i]+p;
      result.n[i]:=s mod 10;
      p:=s div 10;
    end;
  result.len:=longlen(result);
end;

function multi(a,b:tmas):tmas;
var
  i,j,p,s:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for j := nmax downto nmax-b.len do
    for i := nmax downto nmax-a.len do
      if b.n[j]<>0 then
        begin
          s:=a.n[i]*b.n[j]+p;
          result.n[i+j-nmax]:=result.n[i+j-nmax]+s mod 10;
          p:=s div 10;
        end;
  result.len:=longlen(result);
end;

function m2(a:tmas):tmas;
var
  i,p,s:longword;
begin
  fillchar(result,sizeof(result),0);
  p:=0;
  for i := nmax downto nmax-a.len do
    begin
      s:=a.n[i]*2+p;
      result.n[i]:=s mod 10;
      p:=s div 10;
    end;
  result.len:=longlen(result);
end;

var
  n,i,j:longword;
  g,f:array[0..100]of tmas;
begin
  Assign(Input,'goodseq.dat');
  Reset(Input);
  Assign(Output,'goodseq.sol');
  Rewrite(Output);
  read(n);
  fillchar(g,sizeof(g),0);
  fillchar(f,sizeof(f),0);
  g[0].n[nmax]:=1;
  g[0].len:=1;
  f[0].n[nmax]:=1;
  g[1].len:=1;
  f[0].len:=1;
  f[1].len:=1;
  g[1].n[nmax]:=2;
  f[1].n[nmax]:=3;
  if n>1 then
    begin
      for i := 2 to n do
        for j := 1 to i do
          g[i]:=sum(g[i],m2(multi(g[j-1],g[i-j])));
      i:=2;
      for i := 2 to n do
        for j := 1 to i do
          f[i]:=sum(f[i],multi(sum(g[j-1],m2(f[j-1])),f[i-j]));
      i:=1;
      while (i<nmax)and(f[n].n[i]=0) do inc(i);
      for j:=i to nmax do
        write(f[n].n[j]);
      writeln;
    end else writeln(f[n].n[nmax]);
  Close(Input);
  Close(Output);
end.
