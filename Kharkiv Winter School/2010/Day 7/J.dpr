program kontaktu;
{$APPTYPE CONSOLE}
const
  nmax=4200;
  k:array[0..35]of string=('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z');
type
  long=record
         len:longword;
         num:array[1..nmax]of longword;
       end;

function sum(a:long;b:longword):long;
var
  i,p,s:longword;
  res:long;
begin
  p:=0;
  fillchar(res,sizeof(res),0);
  for i:=nmax downto 1 do
    begin
      s:=a.num[i]+b mod 10+p;
     b:=b div 10;
      res.num[i]:=s mod 10;
      p:=s div 10;
    end;
  sum:=res;
end;

function multi(a:long;b:longword):long;
var
  i,p,s:longword;
  res:long;
begin
  p:=0;
  fillchar(res,sizeof(res),0);
  for i:=nmax downto 1 do
    begin
      s:=a.num[i]*b+p;
      res.num[i]:=s mod 10;
      p:=s div 10;
    end;
  multi:=res;
end;


function comp_0(a:long):boolean;
var
  i:longword;
begin
  comp_0:=true;
  for i:=1 to a.len do
    if a.num[i]<>0 then comp_0:=false;
end;

function du(var a:long;b:longword):longword;
var
  i,ost:longword;
  res:long;
begin
  res.len:=a.len;
  ost:=0;
  for i:=1 to a.len do
    begin
      ost:=ost*10+a.num[i];
      res.num[i]:=ost div b;
      ost:=ost mod b;
    end;
  a:=res;
  du:=ost;
end;

var
  p,q,n,m,i,j:longword;
  mas,res:long;
  a,c:string;
  f1,f2:text;
  s,f:longword;
  x:char;
begin
  assign(f1,'input.txt');
  reset(f1);
  assign(f2,'output.txt');
  rewrite(f2);
  readln(f1,p,q);
  i:=0;
  while not eof(f1)do
   begin
     read(f1,x);
     if (ord(x)>=ord('A'))and(ord(q)<=ord('Z')) then
       begin
         inc(i);
         mas.num[i]:=ord(x)-ord('A')+10;
       end   else
       if (ord(x)>=ord('0'))and(ord(q)<=ord('9')) then
         begin
           inc(i);
           mas.num[i]:=ord(x)-48;
         end;
  end;
  res.num[nmax]:=mas.num[1];
  for j:=2 to i do
    res:=sum(multi(res,p),mas.num[j]);
  mas:=res;
  j:=1;
  while (mas.num[j]=0)and(j<nmax) do inc(j);
  i:=1;
  while j<=nmax do
    begin
      mas.num[i]:=mas.num[j];
      mas.num[j]:=0;
      inc(i);
      inc(j);
    end;
  mas.len:=i-1;
  a:='';
  if comp_0(mas)then writeln(f2,0) else
    begin
      while not comp_0(mas) do
       begin
          m:=du(mas,q);
          a:=k[m]+a;
        end;
      writeln(f2,a);
    end;
  close(f1);
  close(f2);
end.
