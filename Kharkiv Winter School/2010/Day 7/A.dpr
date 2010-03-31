program Anti_Grey;
{$APPTYPE CONSOLE}
function st(q1,q2,q3,q4:char):char;
var
  i,a,b,c,d:byte;
begin
  a:=ord(q1)-48;
  b:=ord(q2)-48;
  c:=ord(q3)-48;
  d:=ord(q4)-48;
  i:=a*8+b*4+c*2+d*1;
  if i=0 then st:='0';
  if i=1 then st:='1';
  if i=2 then st:='2';
  if i=3 then st:='3';
  if i=4 then st:='4';
  if i=5 then st:='5';
  if i=6 then st:='6';
  if i=7 then st:='7';
  if i=8 then st:='8';
  if i=9 then st:='9';
  if i=10 then st:='A';
  if i=11 then st:='B';
  if i=12 then st:='C';
  if i=13 then st:='D';
  if i=14 then st:='E';
  if i=15 then st:='F';
end;
var
  s,a,c:string;
  q:char;
  n,i,j,l:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  s:='';
  while not eoln(input) do
    begin
      read(q);
      if q='0' then s:=s+'0000';
      if q='1' then s:=s+'0001';
      if q='2' then s:=s+'0010';
      if q='3' then s:=s+'0011';
      if q='4' then s:=s+'0100';
      if q='5' then s:=s+'0101';
      if q='6' then s:=s+'0110';
      if q='7' then s:=s+'0111';
      if q='8' then s:=s+'1000';
      if q='9' then s:=s+'1001';
      if q='A' then s:=s+'1010';
      if q='B' then s:=s+'1011';
      if q='C' then s:=s+'1100';
      if q='D' then s:=s+'1101';
      if q='E' then s:=s+'1110';
      if q='F' then s:=s+'1111';
    end;
  a:=s;
  for i:=2 to length(s) do
    begin
      if s[i]=a[i-1] then a[i]:='0' else a[i]:='1';
      if i mod 4=0 then
        write(st(a[i-3],a[i-2],a[i-1],a[i]));
    end;
  writeln;
  close(input);
  close(output);
end.
 