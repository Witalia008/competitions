program desiatkovi_drobu;

{$APPTYPE CONSOLE}
const
  nmax=10;
type
 long=record
       len:word;
       num:array[1..nmax+1]of integer;
 end;
procedure inp1(var a:long);
var
  i,j,n:longword;
begin
  i:=0;
  read(n);
  j:=nmax;
  while n>0 do
    begin
      inc(i);
      a.num[j]:=n mod 10;
      n:=n div 10;
      dec(j);
    end;
  a.len:=i;  
end;

function comp_abs(a,b:long):shortint;
var
 i:word;
begin
 i:=1;
 a.num[nmax+1]:=1;
 b.num[nmax+1]:=2;
 while (a.num[i]=b.num[i])do inc(i);
 if i>nmax then comp_abs:=0 else
   if a.num[i]>b.num[i] then comp_abs:=1 else comp_abs:=-1;
end;

function longlen(a:long):word;
var
 i:word;
begin
 i:=1;
 a.num[nmax+1]:=1;
 while (a.num[i]=0) do inc(i);
 if i<=nmax then longlen:=nmax-i+1 else longlen:=1;
end;

procedure minus_abs(a,b:long;var res:long);
var
 i,z:word;
begin
 z:=0;
 fillchar(res,sizeof(res),0);
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

function comp_0(a:long):boolean;
var
 i:word;
begin
 i:=1;
 a.num[nmax+1]:=1;
 while a.num[i]=0 do inc(i);
 comp_0:=(i=nmax+1);
end;

procedure shift(var a:long;k:word);
var
 i:word;
begin
 for i:=1 to nmax-k do
   a.num[i]:=a.num[i+k];
 for i:=nmax-k+1 to nmax do
   a.num[i]:=0;
end;

procedure div_mod(a,b:long;var q,r:long);
var
 i,p,nd,s:word;
begin
 fillchar(q,sizeof(q),0);
 fillchar(r,sizeof(r),0);
 if a.len<b.len then nd:=a.len else nd:=b.len;
 for i:=1 to nd do
   r.num[nmax-nd+i]:=a.num[nmax-a.len+i];
 if a.len>=b.len then
   for p:=nmax-a.len+b.len to nmax do
     begin
       s:=0;
       r.len:=longlen(r);
       while comp_abs(r,b)>=0 do
         begin
           minus_abs(r,b,r);
           inc(s);
         end;
       shift(q,1);
       q.num[nmax]:=s;
       if p<nmax then
         begin
           shift(r,1);
           r.num[nmax]:=a.num[p+1];
         end;
     end;
 q.len:=longlen(q);
 r.len:=longlen(r);    
end;

procedure _gcd(a,b:long;var gcd:long);
var
 q:long;
begin
 fillchar(q,sizeof(q),0);
 while not comp_0(a)and not comp_0(b) do
   if comp_abs(a,b)>0 then
     div_mod(a,b,q,a) else
       div_mod(b,a,q,b);
 if comp_0(a) then gcd:=b else gcd:=a;      
end;

function nMult(a:long;numb:word):word;
var
  i,k:word;
  s,r:long;
begin
  k:=0;
  for i:=1 to nmax do s.num[i]:=0;
  s.num[nmax]:=numb;
  s.len:=1;
  repeat
    div_mod(a,s,a,r);
    if comp_0(r)then inc(k);
  until not comp_0(r);
  nMult:=k;  
end;

function entire(var a,b:long):word;
var
  n:word;
begin
  n:=0;
  shift(a,1);
  a.len:=longlen(a);
  while comp_abs(a,b)>=0 do
    begin
      minus_abs(a,b,a);
      inc(n);
    end;
  entire:=n;  
end;

function outp(a:long):longword;
var
  i,j,ans:longword;
begin
  i:=1;
  ans:=0;
  while (a.num[i]=0)and(i<nmax) do inc(i);
  for j:=i to nmax do
    begin
      write(a.num[j]);
      inc(ans);
      if ans=76 then
        begin
          writeln;;
          ans:=0;
        end;
    end;
  outp:=ans;
end;

procedure div_dec(a,b:long);
var
  grb,s,q,r:long;
  i,k,k2,k5,f:word;
  p:integer;
begin
  k:=0;
  div_mod(a,b,q,r);
  f:=outp(q);
  if not comp_0(r) then
    begin
      write('.');
      inc(f);
      if f=76 then
        begin
          writeln;
          f:=0;
        end;
      _gcd(r,b,grb);
      div_mod(r,grb,r,s);
      div_mod(b,grb,b,s);
      k2:=nMult(b,2);
      k5:=nMult(b,5);
      if k2<k5 then k:=k5 else k:=k2;
      if k<>0 then
        for i:=1 to k do
          begin
            write(entire(r,b));
            inc(f);
            if f=76 then
              begin
                writeln;
                f:=0;
              end;
          end;
      if not comp_0(r) then
        begin
          write('(');
          inc(f);
          if f=76 then
            begin
              writeln;
              f:=0;
            end;
          a:=r;
          repeat
            write(entire(r,b));
            inc(f);
            if f=76 then
              begin
                writeln;
                f:=0;
              end;
          until (comp_abs(a,r)=0);
          write(')');
        end;
    end else write('.0');
end;

var
  a,b:long;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  inp1(a);
  inp1(b);
  div_dec(a,b);
  writeln;
  close(input);
  close(output);
end.
 