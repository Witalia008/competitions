program rac_ch_z_per_drob;
{$APPTYPE CONSOLE}
const
  nmax=200;
type
  long=record
        len:word;
        num:array[1..nmax+1]of smallint;
  end;

procedure inp1(var a:long);
var
  i,j:longword;
  q:char;
begin
  i:=0;
  fillchar(a,sizeof(a),0);
  read(q);
  while (q<>' ') do
    begin
      inc(i);
      a.num[i]:=ord(q)-48;
      read(q);
    end;
  j:=nmax;
  a.len:=i;
  while i>0 do
    begin
      a.num[j]:=a.num[i];
      a.num[i]:=0;
      dec(i);
      dec(j);
    end;
end;

procedure inp2(var a:long);
var
  i,j:longword;
  q:char;
begin
  i:=0;
  fillchar(a,sizeof(a),0);
  while not eoln(input) do
    begin
      read(q);
      inc(i);
      a.num[i]:=ord(q)-48;
    end;
  j:=nmax;
  a.len:=i;
  while i>0 do
    begin
      a.num[j]:=a.num[i];
      a.num[i]:=0;
      dec(i);
      dec(j);
    end;
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

procedure reduce(a,b:long;var n,d:long);
var
  g,r:long;
begin
  _gcd(a,b,g);
  div_mod(a,g,n,r);
  div_mod(b,g,d,r);
end;

procedure outp(a:long);
var
  i,j:word;
begin
  i:=1;
  while (a.num[i]=0)and(i<nmax)do inc(i);
  for j:=i to nmax do write(a.num[j]);
end;

var
  n,i,l,n1,n2:longword;
  j,k:longint;
  q:char;
  s,s1:string;
  a,b,a1,b1:long;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(j,q);
  i:=0;
  while j<>-1 do
    begin
      inc(i);
      write('Case ',i,': ');
      readln(s);
      k:=length(s)-2-j;
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      fillchar(a1,sizeof(a1),0);
      fillchar(b1,sizeof(b1),0);
      for l:=length(s)downto 3 do
        a1.num[nmax-length(s)+l]:=ord(s[l])-48;
      a1.len:=length(s)-2;

      for l:=length(s)-j downto 3 do
        b1.num[nmax-length(s)+l+j]:=ord(s[l])-48;
      b1.len:=(length(s)-2-j);
      minus_abs(a1,b1,a);
      for l:=nmax-j-k+1 to nmax-k do
        b.num[l]:=9;
      b.len:=j+k;
      reduce(a,b,a1,b1);
      outp(a1);
      write('/');
      outp(b1);
      writeln;
      read(j,q);
    end;
  close(input);
  close(output);
end.
