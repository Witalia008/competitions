program dec2one;
{$APPTYPE CONSOLE}
const
  nmax=1100;
type
  tlong=record
    len:word;
    num:array[1..nmax]of shortint;
  end;

function longlen(a:tlong):word;
var
  i:word;
begin
  i:=1;
  while (a.num[i]=0)and(i<nmax) do inc(i);
  longlen:=nmax-i+1;
end;

function comp_0(a:tlong):boolean;
var
  i:word;
  fl:boolean;
begin
  fl:=true;
  for i:=1 to nmax do
    if a.num[i]<>0 then fl:=false;
  comp_0:=fl;
end;

function comp(a,b:tlong):shortint;
var
  i:word;
begin
  i:=1;
  while (a.num[i]=b.num[i])and(i<nmax) do inc(i);
  if a.num[i]=b.num[i] then comp:=0;
  if a.num[i]>b.num[i] then comp:=1;
  if a.num[i]<b.num[i] then comp:=-1;
end;

procedure minus(a,b:tlong;var res:tlong);
var
  i,z:word;
begin
  fillchar(res,sizeof(res),0);
  z:=0;
  for i:=nmax downto 1 do
    begin
      res.num[i]:=a.num[i]-b.num[i]-z;
      if res.num[i]<0 then
        begin
          inc(res.num[i],10);
          z:=1;
        end else z:=0;
    end;
  res.len:=longlen(res);
end;

procedure divmod(a,b:tlong;var res,ost:tlong);
var
  i,j,n:word;
begin
  fillchar(res,sizeof(res),0);
  fillchar(ost,sizeof(ost),0);
  for i:=nmax-a.len+1 to nmax do
    begin
      for j:=1 to nmax-1 do
        ost.num[j]:=ost.num[j+1];
      ost.num[j]:=a.num[i];
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

function comp_ten(a:tlong):boolean;
var
  i:word;
begin
  i:=1;
  while (a.num[i]=0)and(i<nmax) do inc(i);
  if i<nmax then comp_ten:=true else comp_ten:=false;
end;

var
  a,d,os:tlong;
  i,j:word;
  fl:boolean;
  ans:string;
  q:char;
begin
  assign(input,'dec2one.dat');
  reset(input);
  assign(output,'dec2one.res');
  rewrite(output);
  i:=0;
  fillchar(a,sizeof(a),0);
  fillchar(d,sizeof(d),0);
  while not eoln(input) do
    begin
      inc(i);
      read(q);
      a.num[i]:=ord(q)-ord('0');
    end;
  readln;
  a.len:=i;
  j:=nmax;
  while i>0 do
    begin
      a.num[j]:=a.num[i];
      a.num[i]:=0;
      dec(i);
      dec(j);
    end;
  i:=0;
  while not eoln(input) do
    begin
      read(q);
      inc(i);
      d.num[i]:=ord(q)-ord('0');
    end;
  d.len:=i;
  j:=nmax;
  while i>0 do
    begin
      d.num[j]:=d.num[i];
      d.num[i]:=0;
      dec(i);
      dec(j);
    end;
  ans:='';
  if comp_0(a) then ans:='0'; 
  while not comp_0(a) do
    begin
      divmod(a,d,a,os);
      fl:=comp_ten(os);
      if fl then ans:=']'+ans;
      for i:=nmax downto nmax-os.len+1 do
        ans:=chr(os.num[i]+ord('0'))+ans;
      if fl then ans:='['+ans;
    end;
  writeln(ans);  
  close(input);
  close(output);
end.
