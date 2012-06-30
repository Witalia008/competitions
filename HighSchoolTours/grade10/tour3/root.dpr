program root;
{$APPTYPE CONSOLE}
const
  nmax=1010;
type
  tmas=record
         lk,ld,len,_to:word;
         num:array[1..nmax]of byte;
       end;
  tlong=record
    n:array[1..nmax]of shortint;
    l:word;
  end;

procedure shift(var a:tlong;k:longword);
var
  i:longword;
begin
  for i := 1 to nmax-k do
    a.n[i]:=a.n[i+k];
  for i := nmax-k+1 to nmax do
    a.n[i]:=0;
  a.l:=a.l+k;
end;

function longlen(a:tlong):longword;
var
  i:longword;
begin
  i:=1;
  while (a.n[i]=0)and(i<nmax) do inc(i);
  longlen:=nmax-i+1;
end;

function multi(a:tlong;b:longword):tlong;
var
  i,p,s:longword;
begin
  fillchar(result,sizeof(result),0);
  p:=0;
  for i := nmax downto nmax-a.l-1 do
    begin
      s:=a.n[i]*b+p;
      result.n[i]:=s mod 10;
      p:=s div 10;
    end;
  result.l:=longlen(result);
end;

function minus(a,b:tlong):tlong;
var
  i,z:word;
begin
  fillchar(result,sizeof(result),0);
  z:=0;
  for i := nmax downto 1 do
    begin
      result.n[i]:=a.n[i]-b.n[i]-z;
      if result.n[i]<0 then
        begin
          inc(result.n[i],10);
          z:=1;
        end else z:=0;
    end;
  result.l:=longlen(result);
end;

function ss(a:tlong;b:byte):tlong;
begin
  a.n[nmax]:=b;
  ss:=a;
end;

function comp(a,b:tlong):shortint;
var
  i:word;
begin
  i:=1;
  while (a.n[i]=b.n[i])and(i<nmax) do inc(i);
  if a.n[i]=b.n[i] then comp:=0;
  if a.n[i]<b.n[i] then comp:=-1;
  if a.n[i]>b.n[i] then comp:=1;
end;

function comp_0(a:tlong):boolean;
var
  fl:boolean;
  i:word;
begin
  fl:=true;
  for i := 1 to nmax do
    if a.n[i]<>0 then fl:=false;
  comp_0:=fl;
end;
  
var
  a:tmas;
  n,i,j,sol:word;
  an,rr,_2an:tlong;
  ans,s:string;
  q:char;
begin
  assign(input,'root.dat');
  reset(input);
  assign(output,'root.res');
  rewrite(output);
  s:='';
  read(q);
  while q<>' ' do
    begin
      s:=s+q;
      read(q);
    end;
  read(n);
  if pos('.',s)<>0 then
    begin
      if (pos('.',s)-1) mod 2<>0 then s:='0'+s;
      a.lk:=(pos('.',s)-1)div 2;
      a.len:=0;
      while s[1]<>'.' do
        begin
          inc(a.len);
          a.num[a.len]:=(ord(s[1])-48)*10+ord(s[2])-48;
          delete(s,1,2);
        end;
      delete(s,1,1);
      if pos('(',s)<>0 then
        begin
          a.ld:=a.lk+(pos('(',s)-1)div 2;
          n:=(pos(')',s)-pos('(',s))div 2+pos('(',s) div 2;
          delete(s,pos('(',s),1);
          delete(s,pos(')',s),1);
        end else a.ld:=0;
      if length(s)mod 2<>0 then s:=s+'0';
      while length(s)<>0 do
        begin
          inc(a.len);
          a.num[a.len]:=(ord(s[1])-48)*10+ord(s[2])-48;
          delete(s,1,2);
        end;
    end else
    begin
      a.lk:=0;
      if length(s)mod 2<>0 then s:='0'+s;
      a.len:=0;
      while length(s)<>0 do
        begin
          inc(a.len);
          a.num[a.len]:=(ord(s[1])-48)*10+ord(s[2])-48;
          delete(s,1,2);
        end;
    end;
  if a.lk<>0 then a._to:=a.lk+n else a._to:=a.len+n;
  fillchar(an,sizeof(an),0);
  fillchar(rr,sizeof(rr),0);
  fillchar(_2an,sizeof(_2an),0);
  an.n[nmax]:=trunc(sqrt(a.num[1]));
  write(an.n[nmax]);
  an.l:=1;
  rr.n[nmax-1]:=(a.num[1]-an.n[nmax]*an.n[nmax])div 10;
  rr.n[nmax]:=(a.num[1]-an.n[nmax]*an.n[nmax])mod 10;
  shift(rr,2);
  rr.l:=longlen(rr);
  if ((a.len=1)or(a.lk=1))and(n<>0)and(not comp_0(rr) or (a.len>1)) then write('.');
  if (not comp_0(rr))or(a.len>1) then
  for i:=2 to a._to do
    begin
      _2an:=multi(an,20);
      rr.n[nmax-1]:=a.num[i] div 10;
      rr.n[nmax]:=a.num[i] mod 10;
      sol:=0;
      while comp(multi(ss(_2an,sol),sol),rr)<=0 do inc(sol);
      dec(sol);
      write(sol);
      if a.lk<>0 then
        begin
          if (i=a.lk)and(n<>0) then write('.');
        end else
          if (i=a.len)and(n<>0) then write('.');
      shift(an,1);
      an.l:=longlen(an);
      an.n[nmax]:=sol;
      rr:=minus(rr,multi(ss(_2an,sol),sol));
      shift(rr,2);
      if (i=a.ld) then write('(');
      if comp_0(rr) then break;
    end;
  if a.ld<>0 then write(')');
  writeln;
  close(input);
  close(output);
end.

